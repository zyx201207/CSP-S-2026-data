#include<bits/stdc++.h>
using namespace std;

int n, m, a[200001], ans = 0;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    if(m == 1){
        sort(a + 1, a + n + 1);
        printf("%d", a[n]);
        return 0;
    } else if(m == n){
        ans = a[1];
        for(int i = 2; i <= n; i++){
            ans &= a[i];
        }
        printf("%d", ans);
    } else if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if((a[i] & a[j]) > ans){
                    ans = a[i] & a[j];
                }
            }
        }
        printf("%d", ans);
    } else if(m == 3){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    if((a[i] & a[j] & a[k]) > ans){
                        ans = a[i] & a[j] & a[k];
                    }
                }
            }
        }
        printf("%d", ans);
    } else{
        sort(a + 1, a + n + 1);
        printf("%d", a[n]);
    }
    return 0;
}
