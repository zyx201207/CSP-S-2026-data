#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long jian[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    jian[1] = 0;
    int ans = 1;
    for(long long i = 2;i <= n;i++){
        jian[i] = jian[i - 1] + (a[i] - a[i - 1] ) * (i - 1);
        if(jian[i] > m){
            cout << ans;
            return 0;
        }
        ans++;
    }
    cout << n;
    return 0;
}
