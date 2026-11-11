#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    ll n,m,a[N],mxi,mx,ans;
    cin >> n >> m;
    for (ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    ll t;
    ll q = m;
    while (q--){

        for (ll i = 1;i <= n;i++){
            if (a[i] > mx){
                mxi = i;
                mx = a[i];
            }
        }
        a[mxi] = 0;
        ll scmx,scmxi;
        for (int i = 1;i <= n;i++){
            if (scmx < a[i]){
                scmxi = i;
                scmx = a[i];
            }
        }
        if (q == m - 1){
            t += (scmx & mx);
        }


        a[scmxi] = 0;
        a[mxi] = 0;
        mx = 0,scmx = 0,mxi = 0,scmxi = 0;
    }
    cout << "\n" << t;
    return 0;
}
