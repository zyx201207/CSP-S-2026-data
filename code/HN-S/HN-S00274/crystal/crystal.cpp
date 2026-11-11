#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long ans = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long a[n+1];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		long long k=m;
		long long l=i-1, r=i;
		long long num = 1;
		while(k>=0 && l>0){
			if(a[r]-a[l] <= k){
				k -= a[r]-a[l];
				num++;
				l--;
			}
			else break;
		}
		if(num > ans) ans = num;
 	}
 	cout << ans;
	return 0;
} 
