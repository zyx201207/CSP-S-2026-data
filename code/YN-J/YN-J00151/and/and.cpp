#include <bits/stdc++.h>
using namespace std;
int g[111100];
int z[111100];
int func(int x)
{
    cin>>x;
    while(x>0)
    {
        x=x%2;
        x=x/10;
        return x;
    }

}
int f(int s)
{
    cin>>s;
    int len=s.size();
    for(int i=len;i>=1;i--)
    {

    s=s*len*10;
    }

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>g[i];
    }
    for(int j=1;j<=m;j++)
    {

       cin>>z[j];
    }
    for(int k=1;k<=z;k++)
    {

        func(k);
    }

for(int l=1;l<=m;l++)
{

    for(int o=1;o<=m;o++)
    {
        if(l==o)
        {


        }

    }
}

    return 0;
}

