#include <bits/stdc++.h>
using namespace std;

int n, m;
int st[500005], top = 0;
int a[500005];
int cnt[300005];
bool b[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
        memset(st, 0, sizeof(st));
        memset(b, false, sizeof(b));
        for (int j = i; j <= n; j++){
            if (!b[a[j]]){
                st[++top] = a[j];
                b[a[j]] = true;
            } else {
                while (st[top] != a[j]){
                    b[st[top]] = false;
                    top--;
                }
            }
        }
        for (int k = 1; k <= top; k++)
            cnt[st[k]]++;
    }
    for (int i = 1; i <= m; i++)
        printf("%d ", cnt[i]);
    return 0;
}
