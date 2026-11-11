#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500000], ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	sort(a+1,a+1+n);
	if (n == 2 && a[2] - a[1] <= m){
	    ans = 2;
	    cout << ans;
	    return 0;
    }
	else if (n == 2 && a[2] - a[1] != m){
	    ans = 0;
	    cout << ans;
	    return 0;
	}
	for (int i = 1; i <= n/2; i++){
		m -= a[n/2+1] - a[i];
		if (m < 0)
		    break;
		ans++;
		if (a[n-i+1] == a[n/2+1])
		    ans++;
	}
	if (n % 2 == 0 && (a[n/2+2]-a[n/2+1])*ans<=m)
	    ans+=1;
	if (n % 2 == 0)
	    ans-=1;
    cout << ans+1;
	return 0;
} 
