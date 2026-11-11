#include <iostream>
using namespace std;
int n,a[200002],la=0,ra=0;
char c[200002],lc,rc;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> c[i];
	int l=1,r=n;
	while (l<=r){
		la=a[l];
		lc=c[l];
		ra=a[r];
		rc=c[r];
		if (la>=ra){
			if (lc!=rc) ans+=1ll*ra;
			a[l]-=a[r];
			r--;
		}
		else{
			if (lc!=rc) ans+=1ll*la;
			a[r]-=a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}
