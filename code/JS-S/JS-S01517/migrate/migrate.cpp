#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int c,T;
int n,d;
int a[N],dp[N];
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--) {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int l=1;l<=n;l++) {
            int Left=l,Right;
            for(int r=n;r>=l+1;r--) {
                if(a[r]-a[l]<=d) {
                    Right=r;
                    break;
                }
            }
            if(Right-Left==2&&Right!=n) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/