#include<bis/stdc++.h>
using namespace std;
int n,m,d,p;
int cc[10005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int x;
    cin>>x;
    cin>>n>>m>d>>p;

    if(7<x<11)
    {
        int w[m+1];
        for(int i=1;i<=m;i++)cin>>w[i];
        for(int i=1;i<=n;i++)
        {
            int ti;
            cin>>ti;
          for(int i=1;i<=2;i++)
          {
              int nn;
              cin>>nn;
              int oo;
              cin>>oo;
              cc[i]+=oo;

          }

        }
        int uu[p+1];
        for(int i=1;i<=p;i++)
        {
            int aa,bb;
            cin>>aa>>bb;
            for(int j=aa;j<=bb;j++)
            {
                uu[i]+=w[i]+cc[i];
            }
        }
        for(int i=1;i<=p;i++)
        {

            cout<<uu[i];
        }

    }
    int w[m+1];
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int o;
        cin>>o;
        int a[o+1];
        int t[o+1];
        for(int j=1;j<=o;j++)
        {
            cin>>a[j];
            cin>>t[j];
        }

    }
    for(int i=1;i<=p;i++)
    {
        int s,e;
        cin>>s>>e;
        int cnt=w[s];
    }
    return 0;
}
