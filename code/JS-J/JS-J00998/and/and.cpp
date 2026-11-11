#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,a[200005],cnt = 0,max_ = -999999;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cnt = a[1];
    if(m == n){
        for(int i = 1;i <= n;i++){
            cnt = cnt & a[i];
        }
        cout  << cnt;
        return 0;
    }
    if(m == 1){
        sort(a+1,a+n+1);
        cout << a[n];
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cnt = a[i];
        for(int j = i;j <= n;j++){
            for(int k = j;k <= j - 1 + m && k <= n;k++){
                cnt = cnt & a[k];
            }
        }
        if(cnt > max_){
            max_ = cnt;
        }
    }
    cout << max_;
    return 0;
}
