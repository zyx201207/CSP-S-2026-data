#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,inf=1e9;
int x[N],dis[N],f[N],vis[N],fl,ans;
int n,d,c,T;
vector <int> vt[N];
void Dij(int s){
	for(int i=1;i<=n;i++)  f[i]=0;
	int u=s,num=inf,cu=0;  memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)  vis[i]=0;
	dis[s]=0,f[s]=1;
	while(u){
		num=inf;  
		for(int i=s;i<=n;i++){
			if(dis[i]<num&&vis[i]==0)  u=i,num=dis[i];
		}
//		cout<<u<<endl;
		if(u==cu)  break;
		for(auto v:vt[u]){
			if(dis[u]+1<dis[v])  {dis[v]=dis[u]+1;f[v]=f[u];}
			else if(dis[u]+1==dis[v])  f[v]+=f[u];
		}
//		for(int i=1;i<=4;i++)  cout<<dis[i]<<" "<<f[i]<<endl;
//		cout<<endl;
		vis[u]=1;  cu=u;
//		cout<<endl;
	}
//	for(int i=1;i<=4;i++)  cout<<dis[i]<<" "<<f[i]<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)  cin>>x[i];
		for(int i=1;i<=n;i++)  vt[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((x[j]-x[i])<=d)  vt[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			Dij(i);
			for(int j=1;j<=n;j++)  if(f[j]==2)  ans++;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}