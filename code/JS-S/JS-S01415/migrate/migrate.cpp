#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,d,a[2000010];
queue<pair<int,int>> q;
vector<int> v;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    cin>>T;
    while(T--)
    {
        int c,f=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        c=a[2]-a[1];
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]!=c)
            {
                f=-1;
                break;
            }
        }
        if(f==1)
        {
            if(d<2*c)
            {
                cout<<0<<'\n';
                continue;
            }
            int r=d/c;
            cout<<n*(n-1)/2-n+r-1<<'\n';
            continue;
        }
        cout<<n*(n-1)/2<<'\n';
        continue;
    }
    return 0;
}
