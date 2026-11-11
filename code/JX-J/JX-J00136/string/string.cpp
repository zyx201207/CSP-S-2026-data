#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, cnt = 0, sum = 0;
    char h[200010];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; char c, s[10];
        scanf("%d %c", &x, &c);
//        printf("%d %c\n", x, c);
        for (int j = 1; j <= x; j++)
            h[++cnt] = c;
    }
    int l = strlen(h + 1);
    for (int i = 1; i <= l / 2; i++) {
        if (h[i] != h[l + 1 - i])
                sum++;
    }
    printf("%d", sum);
    return 0;
}
