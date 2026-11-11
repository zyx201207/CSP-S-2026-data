#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500017];
long long s[500017];
long long ans = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;	
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
		s[i] = a[i] + s[i - 1];
	
	for(int i = 1;i <= n;i++){
		long long l = i,r = n;
		long long mid;
		long long tempmax = 1;
		while(l <= r){
			mid = (l+r)/2;
			long long need  = (mid-i) * a[mid] - (s[mid-1] - s[i-1]);
			if(need <= m){
				l = mid + 1;
				tempmax = max(tempmax,(long long)(mid-i+1));
			}
			else r = mid-1;
		}
		ans = max(ans,tempmax) ;
	}

	cout << ans;
	
	return 0;
} 
