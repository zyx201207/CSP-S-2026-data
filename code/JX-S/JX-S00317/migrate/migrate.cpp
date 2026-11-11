#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],ans,x2[2000005],a[5005][5005];
int hs(int o,int p,long long q,long long sum)
{
    if((q<=sum)&&(a[o][p]<=d))
        return 1;
    int z=0;
    for(int i=o+1;i<=p;i++)
    {
        if(a[o][i]<=d)
            z+=hs(i,p,q+1,sum);
    }
    return z;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c>>t;
    while(t--)
    {
        cin >>n>>d;
        ans=0;
        memset(x,0,sizeof(x));
        memset(x2,0,sizeof(x2));
        for(int i=1;i<=n;i++)
            cin >>x[i];
        sort(x+1,x+1+n);
        x2[1]=0;
        for(int i=1;i<=n;i++)
            x2[i]=x[i]-x[i-1];
        long long sum=0;
        if(n<=5000)
        {
            for(int i=1;i<=n;i++)
            {
                a[i][i]=0;
                for(int j=i+1;j<=n;j++)
                    a[i][j]=x[j]-x[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            sum=0;
            for(int j=i+1;j<=n;j++)
            {
                sum+=x2[j];
                if(j-i<3)
                    continue;
                if(sum>d)
                {
                    long long w,c=0,d=i;
                    for(int p=i;p<=j;p++)
                    {
                        if((p==j)&&(a[d][p+1]<=d))
                        {
                            c++;
                            break;
                        }
                        if(a[d][p+1]>d)
                        {
                            c++;
                            d=p;
                        }

                    }
                    w=hs(i,j,0,c);
                    if(w==2)
                    {
                        ans++;
                    }
                }
            }
        }
        cout <<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
                a[i][j]=0;
        }
    }
    return 0;
}
