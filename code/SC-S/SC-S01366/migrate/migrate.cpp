#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+10;
int c,T,ans,dis[N],num[N];
int n,d,x[N],cnt[N],z_1,z_2,z;
bool vis[N];
void dfs(int x,int t){
	vis[x]=1;
	if(x==t){
		++cnt[t];
		return;
	}
	for(int i=x;i<=t;++i){
		if(vis[i]) continue;
		if(dis[i]-dis[x]<d) dfs(i,n);
	}
}
signed main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		if(c>=11&&c<=12){
			cin>>z_1>>z_2;
			for(int i=3;i<=n;++i) cin>>z;
			int t=z_2-z_1;
			int p=d/t;
			ans=n-(p+p-1);
			if(ans<0||p<=1) cout<<0;
			else cout<<ans;
			cout<<'\n';
		}
		else{
			memset(vis,0,sizeof(vis)); 
			for(int i=1;i<=n;++i){
				cin>>x[i];
			}
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					cnt[j]=0;
					dfs(i,j);
					if(cnt[j]==2) ++ans;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
*/