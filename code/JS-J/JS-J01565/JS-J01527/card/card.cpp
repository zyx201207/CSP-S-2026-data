#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int ans[300001];
int p[300001];
vector <int> x;
void v(int k)
{
    for(int i=1;i<=m;i++)
    {
        p[i] = -1;
    }
    x.clear();
    for(int i=k;i<=n;i++)
    {
        if(p[a[i]]==-1)
        {
            p[a[i]] = i;
        }
        else
        {
            for(int j=p[a[i]]-k;j<x.size();j++)
            {
                x[j] = -1;
            }
            p[a[i]] = i;
        }
        x.push_back(a[i]);
    }
    /*
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<'\n';
    */
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=-1)
        {
            ans[x[i]]++;
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        v(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
