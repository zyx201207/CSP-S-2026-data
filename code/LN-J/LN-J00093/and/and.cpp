#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 2e5 + 10;
ll num[MAX][20],emty[20],res[20];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,a,highest=0,ans=0;
    cin >> n >> m;
    for (ll i=0;i<n;i++){
        cin >> a;
        for (ll j=0;a>0;j++){
            num[i][j] = a%2;
            a/=2;
            if (j > highest) highest = j;
        }
    }
    for (ll i=highest;i>=0;i--){
        ll cnt = 0;
        for (ll j = 0;j<n;j++)
        if (num[j][i] == 1) cnt++;
        if (cnt >= m){
            res[i] = 1;
            for (ll j = 0;j<n;j++)
            if (num[j][i] == 0) memset(num[j],0,sizeof(num[j]));
        }
    }
    for (ll i=highest;i>=0;i--){
        ans *= 2;
        ans += res[i];
    }
    cout << ans;
    return 0;
}
