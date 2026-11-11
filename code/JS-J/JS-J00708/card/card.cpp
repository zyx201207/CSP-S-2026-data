#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500055, MAXM = 300033;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN], lst[MAXM], ans[MAXM];

int main(){
    //10:12:01 finish(maybe all tasks correct, i don't know how to check it, the output is so big)
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        lst[a[i]] = i;
    }
    for(int i = n;i >= 1;i--){
        if(lst[a[i]] == i){
            b[i] = a[i];
            c[i] = i + 1;
        }
        else{
            b[i] = 0;
            c[i] = lst[a[i]];
        }
    }
    for(int i = 1;i <= n;i++){
        ans[b[i]] += (d[i] + 1);
        d[c[i]] += (d[i] + 1);
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
