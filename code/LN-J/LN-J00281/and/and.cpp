#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int arr[N], ans[N];
int n, m;
int ansmx;
int mx = -9999;
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	if(m == 2){
		
			for(int i = 1; i < n; i++){
				for(int j = i + 1; j <= n; j++){
					int ans = arr[i] & arr[j];
					mx = max(ans, mx);
				}
			}
		
	}
	printf("%lld", mx);
	return 0;
	
}
