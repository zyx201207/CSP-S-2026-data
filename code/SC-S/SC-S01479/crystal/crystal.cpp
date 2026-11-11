#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int MX=5e5+5;
int n, ans; 
ull m;
int a[MX];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin >> n >> m; 
	for(int i=1; i<=n; i++)  cin >> a[i];
	sort(a+1, a+n+1);
	int k=1, t=1;
	for(int i=1; i<n; i++) {
		if((ull)(a[i+1]-a[i])*k>m){
			ans=max(ans, t);
		//	cout << i << ' '<<t<<' '<<m<<"---";
			while((ull)(a[i+1]-a[i])*k>m) {
				k--;
				t--;
				m+=a[i]-a[i-t];
			}
		//	cout << m <<' '<<t<<'\n';
		}
		m-=(a[i+1]-a[i])*k;
		k++;
		t++;
	//	cout << a[i]<< '_' <<a[i+1]<<' '<< k << '\n' << t<<' ' <<m<< '\n';
		
	}
	ans=max(ans, t);
	cout << ans;
    return 0;
}