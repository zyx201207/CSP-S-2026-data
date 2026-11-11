#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;i++)
#define int long long
#define pq priority_queue
#define pb push_back
map<int,int> m;
void solve()
{
    int n,d,ans=0;
    vector<int> v;
    m.clear();
    cin>>n>>d;
    fore(i,0,n)
    {
        int x;
        cin>>x;
        v.pb(x);
        m[x]=1;
    }
    fore(i,0,n)
    {
        if(i+4<=n)
        {
            if(v[i]+d>=v[i+2]&&v[i]+d<v[i+3]&&v[i+1]+d>=v[i+3])
            {
                int p=v[i];
                while(m[p]!=0)
                {
                    ans++;
                    p-=3;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}

