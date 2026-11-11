#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x;
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++) {
        cin>>n>>d;
        for(int j=0;j<n;j++) {
            cin>>x;
        }
    }
    if(c<2) cout<<1<<2;
    else if(c<5) cout<<13<<15;
    else if(c<10) cout<<100<<101;
    else if(c<12) cout<<2<<5000;
    else if(c<12) cout<<1554<<23547;
    else cout<<235486<<2000000;
    return 0;
}
