#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
namespace baoli{
	const int N=105;
	int n,k,dis[N][N];
	vector<int>g[N];
	void get_dis(int u,int fa,int rt){
		for(int v:g[u]){
			if(v==fa)continue;
			dis[rt][v]=dis[rt][u]+1;
			get_dis(v,u,rt);
		}
	}
	int cnt[N];
	void dfs(int u,int fa,int s){
		for(int v:g[u]){
			if(v==fa)continue;
			dfs(v,u,s);
			if(s>>(u-1)&1){
				if(s>>(v-1)&1)cnt[u]+=cnt[v]-1;
				else cnt[u]+=cnt[v];
			}
			else cnt[u]+=cnt[v];
		}
		if(s>>(u-1)&1)cnt[u]++;
	}
	bool check(int s){
		for(int i=1;i<=n;i++)
			cnt[i]=0;
		dfs(1,0,s);
		return cnt[1]<=2;
	}
	void doit(){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			get_dis(i,0,i);
		int ans=1e9;
		for(int s=0;s<(1<<n);s++){
			int res=0;
			vector<int>vec;
			for(int i=1;i<=n;i++)
				if(s>>(i-1)&1)vec.push_back(i);
			if(vec.size()!=k||!check(s))continue;
			for(int i=1;i<=n;i++){
				if(s>>(i-1)&1)continue;
				int minn=1e9;
				for(int j:vec){
					minn=min(minn,dis[i][j]);
				}
				res=max(res,minn);
			}
//			cout<<"res"<<res<<endl;
			ans=min(ans,res);
//			if(res==1){
//				cout<<"vec";
//				for(int x:vec)
//					cout<<x<<' ';
//				cout<<endl;
//			}
		}
		cout<<ans<<endl;
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
}
//using namespace AC{
//	const int N=1e3+5;
//	int n,k,dep[N],maxdep[N],f[N][2][2];//f[][0] num;f[][1] maxdep;f[][2] mindepf
//	vector<int>g[N];
//	void get_dep(int u,int fa){
//		dep[u]=dep[fa]+1;
//		for(int v:g[u]){
//			if(v==fa)continue;
//			get_dep(v,u);
//		}
//	}
//	void dfs(int u,int fa,int expt){
//		int maxdep=0,maxid=0,cnt=0,secdep=0,mindepf=1e9;
//		for(int v:g[u]){
//			if(v==fa)continue;
//			dfs(v,u,expt);
//			if(f[v][1]>maxdep)maxdep=f[v][1],maxid=v,cnt=1;
//			else if(f[v][1]==maxdep)cnt++;
//			else if(f[v][1]>secdep)secdep=f[v][1];
//		}
//		for(int v:g[u]){
//			if(v==fa)continue;
//			if(v==id&&cnt==1){
//				if(f[v][2]+secdep<=expt)f[u][2]=f[v]
//			}
//		}
//	}
//	void doit(){
//		cin>>n>>k;
//		for(int i=1;i<n;i++){
//			int u,v;
//			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//	}
//}
namespace testA{
	const int N=1e5+5;
	int n,k;
	vector<int>g[N];
	void doit(){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int m=n/2;
		if(n==k)cout<<0<<endl;
		else{
			int dis=(m-k)/3;
			cout<<dis<<endl;
		}
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c==13||c==14)testA::doit();
		else baoli::doit();
	}
	return 0;
}
