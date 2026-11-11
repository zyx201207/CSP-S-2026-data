#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,q,n,d,a[2000005];
int fun(int N,int D){
    if(N<D)return 0;
    return N-D+1;
}
signed main()
{
//#ifndef ZYdeBuG
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>q;
    while(q--){
        cin>>n>>d;int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cha=a[2]-a[1];n--;
        int duan=d/cha;
        int i=duan*2-1;
        ans=fun(n,i);
        cout<<ans<<'\n';
    }
    return 0;
}




