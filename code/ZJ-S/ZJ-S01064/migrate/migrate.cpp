#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,i,j,ans,mi,a[2000010],vis[1000],f[1000];
void dfs(int x,int step){
	int i;
	if(x==j){
		f[step]++;
		mi=min(mi,step);
		return;
	}
	for(i=1;i<=n;i++)
		if(!vis[i]&&abs(a[i]-a[x])<=d){
			vis[i]=1;
			dfs(i,step+1);
			vis[i]=0;
		}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c>=1&&c<=2){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(i=1;i<=n;i++) cin>>a[i];
			for(i=1;i<=n;i++)
				for(j=i+1;j<=n;j++){
					mi=1e18;
					memset(f,0,sizeof(f));
					memset(vis,0,sizeof(vis));
					vis[i]=1;
					dfs(i,0);
					if(f[mi]==2) ans++;
				}
			cout<<ans<<"\n";
		}
	}
}
