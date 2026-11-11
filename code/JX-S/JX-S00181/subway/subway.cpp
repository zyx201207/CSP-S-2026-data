#include <bits/stdc++.h>
using namespace std;
int a[2000007];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin >> c >> T;
    while(T--) {
        int n,d;
        cin >> n >>d;
        for(int i=1;i<=n;i++)cin >> a[i];
        int cha = a[2] - a[1];
        if(cha <= d){
                int ans=0;
            ans=n-3;
        cout<<ans<<endl;
        continue;
        }
        else {
            cout<<0;
        continue;
        }
    }
    return 0;
}
//After CSP-J/S 2026 I will AFO.
//Goodbye OI!!!!!
//I love OI and CCF!!!!!!!!!!!!!!!!!!!!!!!
