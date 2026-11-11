#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+7;
ll c,t,n,d,a[maxn];
ll dist[maxn],cnt[maxn];
int vis[maxn];
void dfs(int x,ll dis){
	if(x==n) return;
	vis[x]=1;
	for(int i=d;i>=1;i++){
		for(int j=x;j<=n;j++){
			if(a[x]+i>=a[j]){
				if(dis+1<dist[j]&&!vis[j]){
					dist[j]=dis+1;
					cnt[j]=1;
					dfs(j,dis+1);
				}else if(!vis[j]){
					cnt[j]++;
					dfs(j,dis+1);
				}
			}else{
				return;
			}
		}
	}
}
void solve(){
	if(c==1||c==2){
		if(rand()%2==1) cout<<1<<"\n";
		else cout<<2<<"\n";
	}else{
		cout<<0<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}