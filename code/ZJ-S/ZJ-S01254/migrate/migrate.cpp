#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int c,t,n,d,a[maxn],dis[maxn],f[maxn],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			dis[i]=1;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			if(a[i]+d>=a[n]){
				f[i]=n;
				dis[n]++;
				continue;
			}
			int v=upper_bound(a+1,a+n+1,a[i]+d)-a;
			f[i]=v-1;
			dis[v-1]+=dis[i];
		}
		for(int i=1;i<=n-3;i++){
			if(f[i]==i+2&&(a[i+3]-a[i+1])<=d){
				ans+=dis[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
