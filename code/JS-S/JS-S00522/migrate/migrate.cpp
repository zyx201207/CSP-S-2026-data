#include<iostream>
using namespace std;
long long c,t,n,d,a[2000001];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            __int128 xx=a[2]-a[1];
            if(d<2*xx||d/xx>(n-1)/2) cout<<0<<endl;
            else cout<<(long long)(n-d/xx*2+1)<<endl;
        }
    }
}
