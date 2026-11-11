#include <bits/stdc++.h>
using namespace std;

int n, m, a[500001], q[500001], ans[300001];

int main(){
    freopen("card1.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++)
                if(q[k] == q[j]){
                    for(int l = k; l <= n; l++)
                        q[l] = 0;
                    q[k] = q[j];
                }
       for(int j = 1; j <= n; j++)
            if(q[j] == i)
                ans[i]++;
    }
    for(int i = 1; i <= m; i++)
            printf("%d ", ans[i]);
}
