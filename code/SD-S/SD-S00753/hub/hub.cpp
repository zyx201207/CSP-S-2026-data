#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
by qqqaaazzz

CSP - 2026 !

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/
int n,k;
vector<int>v[1000010];
int dis[1000010];

int dfs(int d,int fa){
	int mx=dis[d];
	for(auto i : v[d]){
		if(i!=fa){
			mx=max(mx,dfs(i,d));
		}
	}
	return mx;
}
int in[1000010];
int x[1000010],y[1000010];

int u[1000010];
mt19937 rd(12357520);

int out[1000010],up[1000010],dp[1000010],huo[1000010];

void dfs1(int d,int fa){
	int mx=0,cmx=0;
	for(auto i : v[d]){
		if(i!=fa){
			dfs1(i,d);
			out[d]=max(out[d],out[i]+1);
			dp[d]=max(dp[d],dp[i]);
			if(out[i]+1>=mx)cmx=mx,mx=out[i]+1;
			else if(out[i]>=cmx)cmx=out[i]+1;
		}
	}
	dp[d]=max(dp[d],mx+cmx);
}
void dfs2(int d,int fa){
	int mx=huo[d],cmx=0,ccmx=0;
	int MX=up[d],CMX=0;
	
	for(auto i : v[d]){
		if(i!=fa){
			if(out[i]+1>=mx)ccmx=cmx,cmx=mx,mx=out[i]+1;
			else if(out[i]+1>=cmx)ccmx=cmx,cmx=out[i]+1;
			else if(out[i]+1>=ccmx)ccmx=out[i]+1;
			
			if(dp[i]>=MX)CMX=MX,MX=dp[i];
			else if(dp[i]>=CMX)CMX=dp[i];
		}
	}
	for(auto i : v[d]){
		if(i!=fa){
			int A;
			if(out[i]+1==mx||out[i]+1==cmx||out[i]+1==ccmx)A=mx+cmx+ccmx-(out[i]+1);
			else A=mx+cmx;
			
			int B;
			if(out[i]+1==mx)B=cmx;
			else B=mx;
			++B;
			
			huo[i]=B;
			up[i]=max(A,(dp[i]==MX?CMX:MX));
			dfs2(i,d);
		}
	}
}
pair<int,int>A;
void go_far(int d,int fa,int dpt){
	A=max(A,{dpt,d});
	for(auto i : v[d]){
		if(i!=fa){
			go_far(i,d,dpt+1);
		}
	}
}
vector<int>all;
bool road(int d,int fa,int qwq){
	bool my=0;
	if(d==qwq)my=1;
	for(auto i : v[d]){
		if(i!=fa)my|=road(i,d,qwq);
	}
	if(my)all.push_back(d);
	return my;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		cin>>x[i]>>y[i];
	}
	if(n==k){
		cout<<0<<"\n";
		return;
	}
	if(k==2){
		for(int i=1;i<=n;i++){
			out[i]=dp[i]=up[i]=huo[i]=0;
			v[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			v[x[i]].push_back(y[i]);
			v[y[i]].push_back(x[i]);
		}
		dfs1(1,0);
		dfs2(1,0);
		int E=999999999;
		for(int i=1;i<=n;i++){
			E=min(E,(max(dp[i],up[i])+1)/2);
//			cout<<dp[i]<<" "<<up[i]<<"?\n";
		}
		cout<<E<<"\n";
		return;
	}
	if(n<=4000){
		int final=999999999;
		for(int i=1;i<=n-1;i++){
			int M=i;
			for(int i=1;i<=n;i++){
				v[i].clear();
				in[i]=0;
			}
			for(int j=1;j<=n-1;j++){
				if(j==M)continue;
				v[x[j]].push_back(y[j]);
				v[y[j]].push_back(x[j]);
				++in[x[j]];
				++in[y[j]];
			}
			
			queue<int>q;
			for(int i=1;i<=n;i++){
				dis[i]=0;
				if(in[i]==1||in[i]==0)q.push(i),dis[i]=1;
			}
			while(!q.empty()){
				if(q.empty())break;//end
				queue<int>nxt;
				while(!q.empty()){
					int f=q.front();
					q.pop();
					for(auto j : v[f]){
						if(dis[j]==0){
							--in[j];
							if(in[j]==1){
								dis[j]=dis[f]+1;
								nxt.push(j);
							}
						}
					}
				}
				swap(q,nxt);
			}
			
			//want ans=k?
			//>k have to die.
			int E=dfs(x[M],y[M]),E2=dfs(y[M],x[M]);
			for(int i=1;i<=n+1;i++)u[i]=0;
			for(int i=1;i<=n;i++)u[dis[i]]++;
			for(int i=n;i>=1;i--){
				u[i]+=u[i+1];
				if(u[i]+(i>E?1:0)+(i>E2?1:0)<=k){
					//oh
					final=min(final,i-1);
				}
			}
	//		cout<<x[i]<<" "<<y[i]<<"!\n";
	//		for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	//		cout<<"^\n";
		}
		cout<<final<<"\n";
	}
	else{
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			v[x[i]].push_back(y[i]);
			v[y[i]].push_back(x[i]);
		}
		
		A={-1,-1};
		go_far(1,0,0);
		int qwq1=A.second;
		A={-1,-1};
		go_far(qwq1,0,0);
		int qwq2=A.second;
		road(qwq1,0,qwq2);
//		cout<<all.size()<<"\n";
		int _=all[all.size()/2],__=all[all.size()/2-1];
//		cout<<_<<" "<<__<<"\n";
		
//		cout<<qwq1<<" "<<qwq2<<"%\n";
		int final=999999999;
		for(int i=1;i<=3;i++){
			int M=rd()%(n-1)+1;
			for(int i=1;i<=n;i++){
				v[i].clear();
				in[i]=0;
			}
			for(int j=1;j<=n-1;j++){
				if(j==M)continue;
				v[x[j]].push_back(y[j]);
				v[y[j]].push_back(x[j]);
				++in[x[j]];
				++in[y[j]];
			}
			
			queue<int>q;
			for(int i=1;i<=n;i++){
				dis[i]=0;
				if(in[i]==1||in[i]==0)q.push(i),dis[i]=1;
			}
			while(!q.empty()){
				if(q.empty())break;//end
				queue<int>nxt;
				while(!q.empty()){
					int f=q.front();
					q.pop();
					for(auto j : v[f]){
						if(dis[j]==0){
							--in[j];
							if(in[j]==1){
								dis[j]=dis[f]+1;
								nxt.push(j);
							}
						}
					}
				}
				swap(q,nxt);
			}
			
			int E=dfs(x[M],y[M]),E2=dfs(y[M],x[M]);
			for(int i=1;i<=n+1;i++)u[i]=0;
			for(int i=1;i<=n;i++)u[dis[i]]++;
			for(int i=n;i>=1;i--){
				u[i]+=u[i+1];
				if(u[i]+(i>E?1:0)+(i>E2?1:0)<=k){
					//oh
					final=min(final,i-1);
				}
			}
		}
		
		for(int i=1;i<=1;i++){
			for(int i=1;i<=n;i++){
				v[i].clear();
				in[i]=0;
			}
			for(int j=1;j<=n-1;j++){
				if(x[j]==_&&y[j]==__)continue;
				if(x[j]==__&&y[j]==_)continue;
				v[x[j]].push_back(y[j]);
				v[y[j]].push_back(x[j]);
				++in[x[j]];
				++in[y[j]];
			}
			
			queue<int>q;
			for(int i=1;i<=n;i++){
				dis[i]=0;
				if(in[i]==1||in[i]==0)q.push(i),dis[i]=1;
			}
			while(!q.empty()){
				if(q.empty())break;//end
				queue<int>nxt;
				while(!q.empty()){
					int f=q.front();
					q.pop();
					for(auto j : v[f]){
						if(dis[j]==0){
							--in[j];
							if(in[j]==1){
								dis[j]=dis[f]+1;
								nxt.push(j);
							}
						}
					}
				}
				swap(q,nxt);
			}
			
			int E=dfs(_,__),E2=dfs(__,_);
			for(int i=1;i<=n+1;i++)u[i]=0;
			for(int i=1;i<=n;i++)u[dis[i]]++;
			for(int i=n;i>=1;i--){
				u[i]+=u[i+1];
				if(u[i]+(i>E?1:0)+(i>E2?1:0)<=k){
					//oh
					final=min(final,i-1);
				}
			}
		}
		cout<<final<<"\n";
	}
//	for(int i=1;i<=n-1;i++){
//		dfs(x[i],y[i]);
//		dfs(y[i],x[i]);
//	}
	//here we xian write a n^2 try try water
	//and pin k=2
	//very strange
	//oh 
	//w tm hui
	//如果结论正确，可以做到 2log，找到两边的直径分别
	//先写 n^2
	//我要开始偷了
	//就算我会了估计也不太可能写完
	//所以，我打算随机100条边然后直径上再把中点附近的50条给跑了 
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	FAST;
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

