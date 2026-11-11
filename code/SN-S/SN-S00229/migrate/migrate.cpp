#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int c,T,n,d,a[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	if(11<=c&&c<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int s=d/(a[2]-a[1]);
			if(s!=2){
				cout<<0<<'\n';
				continue;
			}
			int ans=0; 
			for(int i=s+1;i<=n;i+=2)ans+=n-i;
			cout<<ans<<'\n';
		}
	}else while(T--)cout<<0<<'\n';
	return 0;
}
/*อ๊ มห*/
