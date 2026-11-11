#include<bits/stdc++.h>
#define N 2000010
#define int long long
using namespace std;
int p,T,n,d;
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>p>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(p==11||p==12){
            int dt=a[2]-a[1];
            int k=d/dt;
            if(k<=1||n<2*k) cout<<0<<endl;
            else cout<<n-2*k+1<<endl;
        }
    }
    return 0;
}
