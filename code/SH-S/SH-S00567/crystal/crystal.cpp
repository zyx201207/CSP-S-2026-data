#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i]; 
	sort(a+1,a+1+n);
	for (int i=1,j=1;i<=n;i++){
		m -= (a[i]-a[i-1])*(i-j);
		while (m < 0){
			if (i == j) break;
			m += a[i]-a[j];
			j++;
		}
		ans = max(ans,i-j+1);
	}
	cout << ans << endl;
	return 0;
} 
