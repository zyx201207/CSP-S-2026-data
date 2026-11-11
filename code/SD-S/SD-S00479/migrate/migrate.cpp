#include<bits/stdc++.h>
#define ll long long
#define pr(x) pair<x,x>
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N1=5e3+10,N=2e6+10;
const ll INF=2e18+10;
int n;
ll d;
ll x[N],L[N],R[N];
int pos;
vector<int> g[N1];
void addg_edge(int u,int v)
{
	g[u].push_back(v);
	return;
}
queue<int> q;
ll dis[N1][N1],dp[N1][N1];
void bfs(int s)
{
	up(i,1,n,1){
		dis[s][i]=INF;
		dp[s][i]=0;
	}
	dis[s][s]=0;
	dp[s][s]=1;
	q.push(s);
	int u;
	while(!q.empty()){
		u=q.front();
		//cout<<"Q"<<u<<endl;
		q.pop();
		for(auto v:g[u]){
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				dp[s][v]=dp[s][u];
				//cout<<u<<"UPD"<<v<<' '<<dp[s][v]<<endl;
				q.push(v);
			}
			else if(dis[s][v]==dis[s][u]+1){
				//cout<<v<<"+="<<u<<' '<<dp[s][u]<<' '<<dp[s][v]<<endl;
				dp[s][v]+=dp[s][u];
			}
		}
	}
	return;
}
bool flagA,flagB;
int wb;
int ans;
void init()
{
	if(n<=5000){
		up(i,1,n,1){
			g[i].clear();
		}		
	}
	ans=0;
	flagA=true;
	flagB=false;
	return;
}
void solve()
{
	cin>>n>>d;
	init();
	up(i,1,n,1){
		cin>>x[i];
	}
	up(i,1,n,1){
		if(i>1 && i<n && 2*x[i]!=x[i-1]+x[i+1]){
			flagA=false;
		}
	}
	pos=1;
	up(i,1,n,1){
		while(x[i]-x[pos]>d){
			pos++;
		}
		L[i]=pos;
	}
	pos=1; 
	up(i,1,n,1){
		while(pos+1<=n && x[pos+1]-x[i]<=d){
			pos++;
		}
		R[i]=pos;
	}
	up(i,1,n,1){
		if(L[i]==1 && R[i]==n){
			flagB=true;
			wb=i;
		}
	}
	if(n<=5000){
		pos=1;
		up(i,1,n,1){
			while(pos+1<=n && x[pos+1]-x[i]<=d){
				pos++;
			}
			up(j,i+1,pos,1){
				//cout<<"EDGE"<<i<<' '<<j<<endl;
				addg_edge(i,j);
			}
		}
		up(i,1,n,1){
			bfs(i);
			up(j,i,n,1){
				//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				if(dp[i][j]==2){
					//cout<<"OK"<<i<<' '<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;		
	}
	else if(flagA){
		pos=1;
		int tag=0;
		while(pos+1<=n && x[pos+1]-x[1]<=d){
			pos++;
		}
		tag=pos-1;
		//cout<<"TAG"<<tag<<endl;
		if(tag>1){
			up(i,1,n,1){
				if(i+2*tag-1<=n){
					ans++;
				}
			}
			cout<<ans<<endl;			
		}
		else{
			cout<<0<<endl;
		}
	}
	else if(flagB){
		up(i,1,wb-1,1){
			ans+=n-R[i]+1;
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_=1;
	cin>>c>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}

