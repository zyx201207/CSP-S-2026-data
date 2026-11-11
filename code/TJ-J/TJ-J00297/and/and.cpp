#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],g[200005];
int n,m;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    for(int i=1;i<=n;i++) {cin>>a[i];}
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    map<int,vector<int> > mp;
    for(int i=1;i<=n;i++)
    {
        int t=a[i],cnt=0;
        while(t)
        {
            if(t%2) mp[cnt].push_back(i);
            g[i]+=t%2;
            t/=2;
            cnt++;
        }
    }
    int anss=LLONG_MAX;
    for(int j=32;j>=0;j--)
    {
        if(mp[j].size()>=m)
        {
            auto xxx=mp[j];
            for(int k=0;k<m;k++)
            {

                anss&=a[xxx[k]];
            }
            break;
        }
    }
    cout<<anss;
    return 0;
}

