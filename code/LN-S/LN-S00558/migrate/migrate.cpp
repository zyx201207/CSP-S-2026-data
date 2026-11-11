#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int q=d/abs(a[1]-a[0]);
        if(q<=1)
        {
            cout<<0<<endl;
            continue;
        }
        int w=q-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i+q+w<=n-1)
            {
                ans+=1;
            }
            else
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
