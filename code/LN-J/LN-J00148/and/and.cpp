#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[200005],ans = -2147483648,p,f;
    cin >> m >> n;
    for(int i = 1;i <= m;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        if(ans < a[i]){
            ans = a[i];
            f = i;
        }
    }
    a[f] = 0;
    for(int i = 1;i <= n-1;i++){
        p = 0;
        for(int j = 1;j <= m;j++){
            if(a[j] == 0) continue;
            if(p < (a[j] & ans)){
                p = (a[j] & ans);
                f = j;
            }
        }
        a[f] = 0;
        ans = p;
    }
    cout << ans;
    return 0;
}

