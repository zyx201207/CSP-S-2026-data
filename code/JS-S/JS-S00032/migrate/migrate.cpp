#include <bits/stdc++.h>
#define int long long
#define N 2000100
using namespace std;
int f[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>f[i];
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        int x=d/(f[2]-f[1]);
        for(int i=x+1;i<n;i++){
            if(i%x)
                ans+=(n-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
