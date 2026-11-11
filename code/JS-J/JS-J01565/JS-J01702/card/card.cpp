#include<bits/stdc++.h>
using namespace std;
int n, m, a[500020], s[500030], ans[500030], first[500030];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s[a[i]]++;
        if(first[a[i]] == 0) first[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i - 1; j++){
            s[a[j]]--;
        }
        int k = i;
        for(int j = n; j >= i; j--){
            if(s[a[j]] >= 2){
               k = j;
               break;
            }
        }
        for(int j = k; j <= n; j++){
            ans[a[j]]++;
        }
        if(k != i){
            for(int j = first[a[k]] - 1; j >= 1; j--){
                ans[a[j]]++;
            }
        }
        for(int j = 1; j <= i - 1; j++){
            s[a[j]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
