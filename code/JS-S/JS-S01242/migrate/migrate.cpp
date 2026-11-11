#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c,t,n,d;
long long x[2000005];
const long long inf=LONG_LONG_MAX/2-10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    
    while(t--) {
        cin>>n>>d;
        fill(x,x+n+1,inf);
        
        bool flaga=true;
        ll fstdt=0;
        for(ll i =1; i <=n;i++) {
            cin>>x[i];
            if(i==2)fstdt=abs(x[2]-x[1]);
            else if(i>=2) if (fstdt!=abs(x[i]-x[i-1])) flaga = false;

        }

        if (flaga) {
            if(fstdt >= d) {
                cout << 0 << '\n';
                continue;
            }


            ll d2 = d-fstdt;
            ll realdt = d2+d;
            if(d<fstdt||d>=realdt||d2<=0) {
                cout << 0 << '\n';
                continue;
            }

            ll i =2;
            for(; i <= n ; i++) {
                if ( abs(x[i]-x[1])==realdt) break;
            }
            if ( i == n) {
                if ( abs(x[i]-x[1])==realdt) cout << 0 << '\n';
                else cout << 0 << '\n';
            }
            else {
                cout << ( abs(x[n]-x[i])/fstdt +1  ) << '\n';
            }

        } else {
            cout << 0 << '\n';
        }

    }



    return 0;
}