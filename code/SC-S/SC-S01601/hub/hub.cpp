#include<bits/stdc++.h>
using namespace std;
const int N=100;
int c,T;
int n,k;
int ok[N],dis[N],f[N][N];bool sg[N];
vector<int> e[N];
void dfs(int u,int mk){
	sg[u]=1;
	for(int v:e[u]){
		if(sg[v]||!(1<<(v-1)&mk))continue;
		dfs(v,mk);
	}
}
bool check(int mk){
	int res=0;
	for(int i=1;i<=n;i++)
		if((1<<i-1)&mk)res++;
	if(res!=k)return false;
	int cnt=0;memset(sg,0,sizeof sg);
	for(int i=1;i<=n;i++){
		if(((1<<i-1)&mk)&&!sg[i])dfs(i,mk),cnt++;
	}
	if(cnt<=2)return true;
	return false;
} 
void solve(){
	cin>>n>>k;int ans=1000;
	for(int i=1;i<=n;i++)e[i].clear();
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n-1;i++){
		int u,v;f[i][i]=0;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		f[u][v]=f[v][u]=1;
	}
	f[n][n]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int mk=1;mk<(1<<n);mk++){
		for(int i=1;i<=n;i++)dis[i]=1000;
		if(check(mk)){
//			cout<<mk<<'\n';
			int m=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if((1<<j-1)&mk)
					dis[i]=min(dis[i],f[i][j]);
			int res=0;
			for(int i=1;i<=n;i++){
				res=max(res,dis[i]);
//				cout<<i<<' '<<dis[i]<<'\n';	
			}
			if(res==1) {
				for(int i=1;i<=n;i++){
//					res=max(res,dis[i]);
//					cout<<i<<' '<<dis[i]<<'\n';	
				}
			}
//			cout<<res<<'\n';
			ans=min(ans,res);
		}
	}
	cout<<ans<<'\n';
}
namespace sub2{
	void solve(){
		while(T--){
			scanf("%d%d",&n,&k);
			for(int i=1;i<n;i++){
				int u,v;
				scanf("%d%d",&u,&v);
			}
			n=n/2+2;
			cout<<ceil(1.0*(n-k+1)/4);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(13<=c&&c<=14)sub2::solve();
	else while(T--)solve();
	return 0;
}//25pts