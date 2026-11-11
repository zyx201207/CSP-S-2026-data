#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,d,c,s;
int a[N],dp[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>s;
    while(s--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            int b;
            cin>>b;
            a[i]=b;
        }
    }
    cout<<n;
    return 0;
}
