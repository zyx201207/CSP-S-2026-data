#include<bits/stdc++.h>

using namespace std;

int n, m;
long long a[200005], k, ans = 0;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		if(m <= 2){
			int j = i;
			k = a[j];
			for( ; j <= m + i - 1; j++)
				k &= a[j];
		}
		else{
			k = a[i];
			for(int j = i + 1; j <= m + i - 2; j++)
				k &= a[j];
			}
		if(ans < k)
			ans = k;
	}
	printf("%d", ans);
	return 0;
}
