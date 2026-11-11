#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],dis[5005][5005],num[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(dis,0x3f,sizeof(dis));
        cin>>n>>d;
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            dis[i][i]=0;
            cin>>a[i];
            if(i>=3 && a[i]-a[i-1] != a[i-1]-a[i-2]) f=false;
        }
        if(f)
        {
            long long l=d/(a[2]-a[1]),sum=0;
            for(int i=1;i<=n-l;i++)
            {
                sum+=min(l-1,n-i-l);
            }
            cout<<sum<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int j=i+1;
            while(a[j]-a[i]<=d)
            {
                dis[i][j]=1;
                num[i][j]=1;
                j++;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    if(dis[i][j]==dis[i][k]+dis[k][j]) num[i][j]++;
                    if(dis[i][j]<dis[i][k]+dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                        num[i][j]=1;
                    }
                }
            }
        }
        int sum=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(num[i][j]==2) sum++;
            }
        }
        cout<<sum<<endl;
    }
}
