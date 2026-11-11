#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
int c,T,n,d;
int a[MAXN],p[MAXN];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> d;
        bool bfa=1; int bfac;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            p[i] = a[i] - a[i-1];
        }
        for(int i=3;i<=n;i++) if(p[i]!=p[i-1]) bfa = 0;
        if(bfa==1){
            bfac = p[n];
            if(2*bfac > d) cout << 0 << "\n";
            else cout << n-3 << "\n";
            continue;
        }
        sort(a+1,a+n+1);
        if(n<=5000){
            int sum=0,ans=0;
            for(int i=1;i<=n-2;i++){
                for(int j=i+2;j<=n;j++){
                    sum = 0;
                    for(int k=i+1;k<=j-1;k++){
                        if(a[j]-a[k]<=d && a[k]-a[i]<=d)sum++;
                    }
                    if(sum==2) ans++;
                }
            }
            cout << ans << "\n";
        }else cout << 1 << "\n";
    }
    return 0;
}
