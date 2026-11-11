#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
bool vis1[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        memset(vis1,0,sizeof(vis1));
        v.clear();
        for(int j=i;j<=n;j++)
        {
            if(vis1[a[j]]==1)
            {
                memset(vis1,0,sizeof(vis1));
                v.clear();
            }
            vis1[a[j]]=1;
            v.push_back(a[j]);
        }
        for(int j=0;j<v.size();j++)
        {
            b[v[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}
