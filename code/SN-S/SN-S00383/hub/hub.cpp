#include<bits/stdc++.h>
#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=1e2+5;
const int M=1e3+5;
const int inf=1e18;
int C,T,n,K;
vector<int> v[M];
//int dp[N][N][3][2];
//int dep[N],maxn[N];
//void dfs(int id,int fa){
//	dep[id]=dep[fa]+1;maxn[id]=dep[id];
//	for(int i=0;i<v[id].size();i++){
//		int now=v[id][i];
//		if(now==fa)continue;
//		dfs(now,id);maxn[id]=max(maxn[id],maxn[now]);
//	} 
//	dp[id][1][1][1]=maxn[id]-dep[id];
//	for(int i=0;i<v[id].size();i++)
//	{
//		int now=v[id][i];
//		if(now==fa)continue;
//		//O(N*2*2*N*N*3*3)
//		for(int u=0;u<=1;u++)//id自己有没有建发电站 
//		{
//			for(int j=0;j<=K;j++){//id用了j个发电站了 
//				for(int k=0;k<=j;k++){//now用了k个发电站 
//					for(int op=0;op<=1;op++){//now用没用 
//						for(int l=1;l<=2;l++)//id已经构造几个联通块了 
//						{
//							for(int r=0;r<=2;r++)//now构造几个联通块了 
//							{
//								dp[id][j][l][u]=max(dp[id][j][l][u]);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
int ans,maxn;
int dis[N];
bool op[N],use[N];
void check(int id,int fa){
	use[id]=true;
	for(int i=0;i<v[id].size();i++){
		int now=v[id][i];
		if(use[now]||(!op[now]))continue;
		check(now,id);
	}
}
queue<int> q;
void jmc(int id,int pls){
	if(id>n){
		if(pls!=K)return ;
		int cnt=0;maxn=0;
		for(int i=1;i<=n;i++)use[i]=false;
		for(int i=1;i<=n;i++)
			if(op[i]&&(!use[i]))
				check(i,0),++cnt;
		if(cnt>2)return ;
		for(int i=1;i<=n;i++){
			if(op[i])dis[i]=0,q.push(i);
			else dis[i]=inf;
		}
		while(!q.empty()){
			int id=q.front();q.pop();
			maxn=max(maxn,dis[id]);
			for(int i=0;i<v[id].size();i++){
				int now=v[id][i];
				if(dis[id]+1<dis[now]){
					dis[now]=dis[id]+1;
					q.push(now);
				}
			}
		}
		ans=min(ans,maxn);
		return ;
	}
	op[id]=true;
	jmc(id+1,pls+1);
	op[id]=false;
	jmc(id+1,pls);
}
int dep[N],mx[N];
void dfs(int id,int fa){
	dep[id]=dep[fa]+1;mx[id]=dep[id];
	for(int i=0;i<v[id].size();i++){
		int now=v[id][i];
		if(now==fa)continue;
		dfs(now,id);mx[id]=max(mx[id],mx[now]);
	}
}
int minn,Rt;
void find(int id,int fa){
	for(int i=0;i<v[id].size();i++){
		int now=v[id][i];
		if(now==fa)continue;
		find(now,id);
	}
	int x=max(dep[id]-1,mx[id]-dep[id]);
	if(minn>x)minn=x,Rt=id;
}
signed main(){
	O1145 O1919
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=1e18;
		if(n<=10){
			jmc(1,0);
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				dfs(i,0);
				priority_queue<int> s;
				for(int j=0;j<v[i].size();j++){
					int now=v[i][j];
					s.push(mx[now]-1);
				}
				for(int j=0;j<v[i].size();j++){
					int now=v[i][j],Mx=s.top();
					bool del=false;
					if(s.top()==mx[now]-1)s.pop(),del=true;
					if(s.empty())Mx=0;
					else Mx=s.top();
					minn=1e18;
					find(now,i);
					ans=min(ans,max(minn,Mx));
					if(del)s.push(mx[now]-1);
				}
			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)v[i].clear();
	}
	return 0;
}
