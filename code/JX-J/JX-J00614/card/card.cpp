#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],z[500010],s[300010],c;
void dfs(int x,int j)
{
    if(j==n)
    {
        for(int i=1;i<=n;i++)
        {
            s[z[i]]++;
        }
    }
    c=n+1;
    for(int i=1;i<=n;i++)
    {
        if(z[i]!=a[j])
        {
            z[j]=a[j];
            dfs(x,j+1);
        }
        else
        {

            c=i;
        }
    }
    for(int i=c;i<=n;i++)
    {
        z[i]=0;
        z[c]=a[j];
    }
    dfs(x,j+1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,1);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<s[i];
    }
    return 0;
}
