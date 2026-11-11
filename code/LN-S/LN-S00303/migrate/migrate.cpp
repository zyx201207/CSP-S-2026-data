#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,T;
int n,d;
int a[3001000];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c >>T;
    while(T--){
        cin >>n >>d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        if(d/(a[2]-a[1])<=1){
            cout << 0 <<endl;
            continue;
        }
        int times=d/(a[2]-a[1]);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=max(min((n+1-i)/times-1,(int)1),(int)0);
        }
        cout <<ans <<endl;
    }

    return 0;
}
