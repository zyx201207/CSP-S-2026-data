#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mn=2e6+10;
int c,t,a[mn],cha[mn],chapro[mn],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		ans=0;
		memset(a,0,sizeof(a));
		memset(cha,0,sizeof(cha));
		memset(chapro,0,sizeof(chapro));
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=3;i<=n;i++){
			cha[i]=a[i]-a[i-1];
		}
		for(int i=4;i<=n;i++){
			chapro[i]=cha[i]-cha[i-1];
		}
		for(int i=4;i<=n;i++){
			if(chapro[i]<=d && chapro[i-1]<=d && chapro[i-2]<=d && chapro[i-3]<=d && chapro[i]-chapro[i-2]<=d && chapro[i-1]-chapro[i-3]<=d){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
