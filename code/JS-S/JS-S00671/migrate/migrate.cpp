#include<bits/stdc++.h>
using namespace std;
long long c,t,x[200005],n,d;
long long dfs(long long l,long long r,long long cnt,int ci)
{
    if(l==r)
    {
        if(ci==cnt)
        {
            return 1;
        }
    }
    long long res=0;
    for(int i=l+1;i<=r;i++)
    {
        if(x[i]-x[l]>d) break;
        res+=dfs(i,r,cnt,ci+1);
    }
    return res;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(13<=c&&c<=14)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(n==1)
            {
                cout<<0<<'\n';
                continue;
            }
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+2;j<=n;j++)
                {
                    long long l=j-d,r=i+d,num=0;
                    for(int k=i+1;k<=j-1;k++)
                    {
                        if(l<=x[k]&&x[k]<=r) num++;
                    }
                    if(num==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    else if(11<=c&&c<=12)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(n==1)
            {
                cout<<0<<'\n';
                continue;
            }
            long long b=x[2]-x[1];
            long long c=d/b;
            long long num=0;
            for(long long i=1;i<n;i++)
            {
                 long long cnt=(i%c==0?(i/c):(i/c+1));
                 long long y=c-i%c;
                 if(y==1&&cnt==2) num+=(n-i);
            }
            cout<<num<<'\n';
        }
    }
    else
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(n==1)
            {
                cout<<0<<'\n';
                continue;
            }
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+3;j<=n;j++)
                {
                    long long last=i,cnt=1;
                    for(int k=i+1;k<=j;k++)
                    {
                        if(x[k]-x[last]>d)
                        {
                            last=k-1;
                            cnt++;
                        }
                    }
                    long long num=dfs(i,j,cnt,0);
                    if(num==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
