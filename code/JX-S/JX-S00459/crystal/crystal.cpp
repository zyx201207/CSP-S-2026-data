#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500010] = {},ans = 0,b[500010] = {};
    cin >> n >> m;
    for(long long i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(long long i = 1;i<=n;i++){
        b[i] = a[i+1]-a[i];
    }
    sort(b+1,b+n+1);
    for(long long i = 1;i<=n;i++){
        if(ans>m){
            cout << i-1;
            return 0;
        }
        else if(ans==m){
            cout << i;
            return 0;
        }
        else if(ans<m){
            ans+=b[i];
        }
    }
    return 0;
}
