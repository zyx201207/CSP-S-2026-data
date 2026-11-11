#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,T,n,m,a[N],cnt[N],vis[N],ok=1,cha;
void dfs(int k,int tot){
	for(int i=1;i<=n;i++){
		if(i==k) continue;
		if(abs(a[i]-a[k])>m) continue;
		if(tot==cnt[i]){
			vis[i]++;
		}else if(tot<cnt[i]){
			vis[i]=1;
			cnt[i]=tot;
		}else{
			continue;
		}
		dfs(i,tot+1);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) cha=a[2]-a[1];
		if(i>2){
			if(cha!=a[i]-a[i-1]) ok=0;
		}
	}
	if(abs(a[n]-a[1])<=2*m) ok=1;
	if(n<=20){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[j]=1e18;
				vis[j]=0;
			}
			cnt[i]=0;
			dfs(i,1);
			for(int j=i+1;j<=n;j++){
				if(vis[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	else if(ok){
		cout<<0<<"\n";
	}else cout<<1<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
