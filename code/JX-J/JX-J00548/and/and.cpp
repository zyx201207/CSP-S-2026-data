#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    long long ans = a[n - 1];
    for(int i = n - 2; i > n - m - 1; i--){
        ans &= a[i - 1];
    }
    printf("%lld", ans);
	return 0;
}
