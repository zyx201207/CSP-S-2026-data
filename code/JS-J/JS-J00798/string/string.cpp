#include <bits/stdc++.h>
using namespace std;

long long ans;
int n, a[200001];
char c[5], s[200001];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        scanf(" ");
        scanf("%c", &c[i]);
    }
    for(int i = 1; i <= (n - 1) / 2 + 1; i++){
        if(a[i] == a[n - i + 1])
            if(c[i] != c[n - i + 1])
                ans += a[i];

    }
    printf("%lld\n", ans);
}
