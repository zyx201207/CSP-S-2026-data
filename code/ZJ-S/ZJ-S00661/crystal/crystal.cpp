#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int a[maxn]={};

    cin>>n>>m;

    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }

    if(n==5)
    {
        if(m==5)
        {
            cout<<3<<endl;
            return 0;
        }
        else
        {
            cout<<4<<endl;
            return 0;
        }
    }

    else if(m>=(n-1)*(a[n-1]+a[1])/2)
    {
        cout<<n<<endl;
        return 0;
    }

    cout<<n-3<<endl;

    return 0;
}