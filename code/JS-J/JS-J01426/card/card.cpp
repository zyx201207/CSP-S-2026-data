#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int a[N];
int b[N];
int c[N];
int ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    for(int t=1;t<=n;t++)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=t;i<=n;i++)
        {
            c[i]=a[i];
            if(b[c[i]])
            {
                for(int j=b[c[i]];j<i;j++)
                {
                    b[c[j]]=0;
                    c[j]=0;
                }
            }
            b[c[i]]=i;
        }
        for(int i=t;i<=n;i++)
        {
            ans[c[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
