#include<bits/stdc++.h>
using namespace std;
int maxn=-1;
int n,m;
int a[1000000];
void dfs(int s,int u,int k)
{
    if(k==m) maxn=max(maxn,s);
    else
    {
        for(int j=u+1;j<n;j++)
        {
            dfs(s & a[j],j,k+1);
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(-1,-1,0);
    cout<<maxn;
    return 0;
}
