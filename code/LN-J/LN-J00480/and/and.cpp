#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],n,m,b[maxn];
vector<int> h[35],g[35];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<=30;j++)
        {
            if(a[i]&(1<<j))
            {
                h[j].push_back(i);
            }
        }
    }
    int ans=0;

    while(8)
    {
        int z=-1;
        for(int i=30;i>=0;i--)
        {
            if(h[i].size()>=m)
            {
                z=i;
                break;
            }
        }
        if(z==-1){
            cout<<ans;
            return 0;
        }
        for(int i=0;i<=32;i++)
         {
            if(i!=z)
            {
                h[i].clear();
            }
        }
        for(int v:h[z])
        {
            a[v]-=(1<<z);
            for(int j=0;j<=30;j++)
            {
                if(a[v]&(1<<j))
                {
                    h[j].push_back(v);
                }
            }
        }
        h[z].clear();
        ans+=(1<<z);
    }

    return 0;
}
