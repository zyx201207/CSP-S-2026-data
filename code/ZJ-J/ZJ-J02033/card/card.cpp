#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int a[500005];
int b[300005];
int n,m;
void solve(int l,int r)
{
    int tmp[300005]={};
    for(int i=l;i<=r;i++)
    {
        if(tmp[a[i]])
        {
            int j=i-1;
            while(a[j]!=a[i])
            {
                tmp[a[j]]=0;
                j--;
            }
        }
        tmp[a[i]]=1;
    }
    for(int j=1;j<=m;j++)
    {
        b[j]+=tmp[j];
    }
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        solve(i,n);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

