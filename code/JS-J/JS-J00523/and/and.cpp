#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxx;
void dfs(int dep,int andd,int id)
{
    //cout<<andd<<" "<<dep<<endl;
    if(dep==m)
    {
        
        maxx=max(maxx,andd);
    }
    if(dep!=0)
    {
        for(int i=id+1;i<=n;i++)
        {
            dfs(dep+1,andd&a[i],i);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            dfs(1,a[i],i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    // int a=3&15;
    // cout<<a<<endl;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<maxx<<"\n";
    return 0;
}