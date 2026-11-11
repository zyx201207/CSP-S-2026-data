#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t,n,d,a[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int x=d/(a[2]-a[1]);
        if(x+x<=n&&d!=1&&x>1)
            cout<<n-x-x+1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
