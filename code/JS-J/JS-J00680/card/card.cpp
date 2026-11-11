#include<bits/stdc++.h>
using namespace std;
int a[600000],c[600000],len=1,d[600000];
bool b[600000]={false};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=m;i++)b[i]=false;
        len=1;
        for(int i=j;i<=n;i++)
        {
            if(b[a[i]])
            {
                while(c[--len-1]!=a[i]);
                b[a[i]]=false;
                len++;
            }
            else
            {
                b[a[i]]=true;
                c[len++]=a[i];
            }
        }
        for(int i=1;i<=len-1;i++)
        {
            d[c[i]]+=b[i];

        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<d[i]<<' ';
    }
    return 0;
}
