#include<bits/stdc++.h>
using namespace std;
#define int long long
int e[200005];
int ed[200005];
int a[200005];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			e[i]=ed[i]=1;
		}
		for(int i=1;i<=n;i++){
			e[(int)(upper_bound(a+1,a+n+1,a[i]+d)-a-1)]+=e[i];
		}
		for(int i=n;i>=1;i--){
			ed[(int)(lower_bound(a+1,a+n+1,a[i]-d)-a)]+=ed[i];
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]>d&&((a[i+2]-a[i]<=d&&a[i+1]-a[i]<=d)&&(a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d))){
				ans+=e[i]*ed[i+3];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}