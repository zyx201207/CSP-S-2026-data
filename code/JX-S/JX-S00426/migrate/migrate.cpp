#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],dist[5005][5005],f[5005][5005],ans;
bool pan[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for(int e=1;e<=t;e++)
    {
        ans=0;
        cin>>n>>d;
        if(n<4)
        {
            cout<<0<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        cin>>a[i];
        if(c==11||c==12)
        {
            if(d==2*(a[2]-a[1]))
                cout<<n-3<<"\n";
            else
                cout<<0<<"\n";
        }
        if(c<=10)
        {
            memset(f,0,sizeof f);
            memset(dist,0,sizeof dist);
            for(int i=1;i<n-1;i++)
            {
                for(int k=i+1;k<n;k++)
                {
                    for(int j=k+1;j<=n;j++)
                    {
                        if(a[j]-a[i]<=d)
                            dist[i][j]=1;
                        if(a[j]-a[k]<=d)
                            dist[k][j]=1;
                        if(a[k]-a[i]<=d)
                            dist[i][k]=1;
                        if(dist[i][j]==0&&dist[i][k]!=0&&dist[k][j]!=0)
                            dist[i][j]=dist[i][k]+dist[k][j];
                        else
                            if(dist[i][k]!=0&&dist[k][j]!=0)
                            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
            for(int i=1;i<n-1;i++)
            {
                for(int k=i+1;k<n;k++)
                {
                    for(int j=k+1;j<=n;j++)
                    {
                        if(dist[i][j]==0)
                            continue;
                        if(dist[i][j]==dist[i][k]+dist[k][j])
                            f[i][j]++;
                    }
                }
            }
            for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
            if(f[i][j]==2)
            ans++;
            cout<<ans<<"\n";
        }
        if(c==13||c==14)
        {
            int idx;
            for(int i=2;i<=n;i++)
            {
                dist[i-1][i]=1;
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
                idx=i;
            }
            int l=1,r=4;
            while(r<=n)
            {
                if(a[r]-a[l]<=d)
                {
                    l++,r++;
                    continue;
                }
                ans++;
                l++,r++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
