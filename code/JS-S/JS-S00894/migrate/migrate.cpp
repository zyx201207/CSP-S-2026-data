#include<bits/stdc++.h>
using namespace std;
long long x[2000005],ji,vi[2000005],ne;
void dfs(long long n,long long d,long long q,long long j,long long ans,long long ans1)
{
    if(q==j)
    {

        ans1=min(ans1,ans);
        ji=ans1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vi[i]==0)
        {

               if(x[i]-x[q]>=0)
        {
           if(x[i]-x[q]<=d)
    {
         vi[i]=1;
        ans+=x[i]-x[q];
        dfs(n,d,q,j,ans,ans1);
        ans-=x[i]-x[q];
         vi[i]=0;
    }

        }
   else{
           if(x[q]-x[i]<=d)
    {

        vi[i]=1;
        ans+=x[q]-x[q];
        dfs(n,d,q,j,ans,ans1);
        ans-=x[q]-x[i];
         vi[i]=0;
    }
   }
        }


    }

}
void dfs1(long long mi,long long n,long long d,long long q,long long j,long long ans)
{
    if(q==j && ans==mi)
    {
        ne++;

    }
    for(int i=1;i<=n;i++)
    {
        if(vi[i]==0)
        {

               if(x[i]-x[q]>=0)
        {
           if(x[i]-x[q]<=d)
    {
         vi[i]=1;
        ans+=x[i]-x[q];
        dfs(mi,n,d,q,j,ans);
        ans-=x[i]-x[q];
         vi[i]=0;
    }

        }
   else{
           if(x[q]-x[i]<=d)
    {

        vi[i]=1;
        ans+=x[q]-x[q];
        dfs(mi,n,d,q,j,ans);
        ans-=x[q]-x[i];
         vi[i]=0;
    }
   }
        }


    }

}
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
long long c,t;
cin >> c >> t;
while(t--)
{
    ne=0;
    for(int i=1;i<=2000005;i++)
    {

        vi[i]=0;
    }
   long long n,d,anss=0;
   cin >> n >> d;

    for(int i=1;i<=n;i++)
    {

        cin >> x[i];
    } for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
    {
        vi[i]=1;
        dfs(n,d,i,j,0,0);
        long long mi=ji;
        dfs1(mi,n,d,i,j,0);
        if(ne==2)
        {
            anss++;

        }
    }

    }
    cout << anss;
}
return 0;
}
