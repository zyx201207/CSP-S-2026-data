#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn,mp;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        maxn=-1;
        for(int j=1;j<=n;j++)
        {
            if(a[j]>maxn)
            {
                maxn=a[j];
                mp=j;
            }
        }
        if(i!=m)
        {
            a[mp]=-1;
        }
        else
        {
            cout<<maxn;
        }
    }
    return 0;

}
