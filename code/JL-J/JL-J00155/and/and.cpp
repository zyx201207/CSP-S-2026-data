#include<bits/stdc++.h>
using namespace std;
int a[200000];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int bt=30; bt>=0; bt--){
        sort(a, a+n, cmp);
        bool flag = false;
        if( a[m-1] >= (1<<bt) && a[m-1] != -1 ){
            ans += (1 << bt);
            flag = true;
        }
        for(int i=0; i<n; i++){
            if( a[i] == -1 ) break;
            if( a[i] < (1<<bt) && flag ) a[i] = -1;
            if( a[i] >= (1<<bt) ) a[i] -= (1 << bt);
        }
    }
    printf("%d", ans);
    return 0;
}
