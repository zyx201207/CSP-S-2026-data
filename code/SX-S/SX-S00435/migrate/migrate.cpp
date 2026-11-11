#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6+50;
int c,T;
int n,d;
int x[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        int dist=x[2]-x[1];
        int cnt=floor(double(d)/double(dist))*1ll;
        if(cnt==0){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            int l=i+cnt+1ll,r=min(n,i+cnt+cnt-1ll);
            if(l>n)continue;
            int res=max(0ll,r-l+1ll);
            ans+=res;
        }
        cout<<ans<<endl;
    }

    return 0;
}