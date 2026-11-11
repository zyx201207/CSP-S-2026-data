#include<bits/stdc++.h>
using namespace std;


long long m,n,ans,l,r,mid;
long long a[1000005],sum[1000005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	if(a[1] == a[n]){
		cout << n << '\n'; 
		return 0;
	}
	
	sum[0] = 0;
	for(int i = 1; i <= n; ++i){
		sum[i] = sum[i - 1] + a[i];
	}
	
	ans = 1;
	for(int i = n; i > ans; --i){
		l = 1;
		r = i;
//		cout << i << '\n';
		while(l!=r-1){
			mid = (l + r) / 2;
			if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1])<=m){
				r = mid;
			}else{
				l = mid;
			}
//			cout << l << ' ' << r << '\n'; 
		}
		if (i * a[i] - (sum[i] - sum[0])<=m) r = 1;
		if(i - r + 1 > ans) ans = i - r + 1;
//		cout << 'a' << ans << '\n'; 
	}
	
	cout << ans << '\n';
	

    return 0;
}
