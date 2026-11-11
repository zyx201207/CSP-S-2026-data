#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[10000000];
bool ff(int x,int y,int d)
{
    for(int i=x;i<y;i++)
    {

        if(a[i+1]-a[i]>d)
        {
            return false;
        }
    }
    if(y-x==3)
    {
        if((a[x+1]-a[x]<=d && a[x+3]-a[x+1]<=d)&&(a[x+2]-a[x]<=d && a[x+3]-a[x+2]<=d))
            return true;
        else
        {
            return false;
        }
    }
    if(y-x==4)
    {
        int qe=0,qq=0;
        int u=a[x];
        for(int i=y;i>=x;i--)
        {
            if(a[i]-u<=d)
            {
                i=y+1;
                u=a[i];
                qe++;
            }
            if(u==a[y])break;
        }
        if(qe==4)
        {
            return false;
        }
        if(qe==3)
        {
            if((a[x+1]-a[x]<=d && a[x+2]-a[x+1]<=d) && a[x+4]-a[x+2]<=d)qq++;
            if((a[x+1]-a[x]<=d && a[x+3]-a[x+1]<=d) && a[x+4]-a[x+3]<=d)qq++;
            if((a[x+2]-a[x]<=d && a[x+3]-a[x+2]<=d) && a[x+4]-a[x+3]<=d)qq++;
            if(qq==2)return true;
            else
            {
                return false;
            }
        }
        if(qe==2)
        {
            if(a[x+1]-a[x]<=d && a[x+4]-a[x+1]<=d)qq++;
            if(a[x+2]-a[x]<=d && a[x+4]-a[x+2]<=d)qq++;
            if(a[x+3]-a[x]<=d && a[x+4]-a[x+3]<=d)qq++;
            if(qq=2)return true;
            else
            {
                return false;
            }
        }
        return false;
    }
    return false;
}
int main()
{

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(long long j=1;j<n+1;j++)
        {
            cin>>a[j];
        }
        long long ans=0;
        for(int j=1;j<=n-3;j++)
        {
            for(int k=j+3;k<=n;k++)
            {
                if(a[k]-a[j]<=d)continue;
                if(ff(j,k,d))
                {
                    ans++;
                }
                else break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
