#include<bits/stdc++.h>
using namespace std;
int a[500000];
int lst[300010];
int cnt[300010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=n-1; i>=0; i--) if( lst[a[i]] == 0 ) lst[a[i]] = i;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if( lst[a[j]] > 0 ) j = lst[a[j]];
            cnt[a[j]] ++;
        }
    }
    for(int i=1; i<=m; i++){
        printf("%d ", cnt[i]);
    }
    return 0;
}
