#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],f[500010],ans[500010];
vector<int> v;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[j]=0;
        }
        v.clear();
        for(int j=i;j<=n;j++)
        {
            if(f[a[j]]==1)
            {
                for(int q=1;q<=m;q++)
                {
                    f[q]=0;
                }
                int g=0,ff=0;
                for(auto i:v)
                {
                    if(i==a[j])
                    {
                        ff=1;
                    }
                    if(!ff)
                    {
                       g++;
                       f[i]=1;
                    }
                }
                v.erase(v.begin()+g,v.end());
                v.push_back(a[j]);
                f[a[j]]=1;
            }
            else
            {
                v.push_back(a[j]);
                f[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            f[i]=0;
        }
        for(auto j:v)
        {
            if(f[j]==0)
            {
                ans[j]++;
                f[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
