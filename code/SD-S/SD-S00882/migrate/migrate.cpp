#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000006;
int c,T;
ll d;
int n;
ll a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c>>T;
	while (T--) {
		ll ans=0;
		bool flag=1;
		cin>>n>>d;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			if (abs(a[i]-a[i-1])>d) flag=0;
		}
		if (!flag) {
			cout<<0<<'\n';
			break;
		}
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				if ((a[j]-a[i])%d==0) continue;
				if (a[j]-a[i]<d) continue;
				ll dis=(a[j]-a[i])/d+1;
				if (j-i-1==dis) ans++;
//				ll dis=1,mxd=0;
//				for (int k=i+1;k<=j;k++) {
//					if (a[k]-a[j]+mxd<=d) ;
//					else dis++;
//				}
				
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
//
