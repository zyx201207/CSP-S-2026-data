#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],pres[200005],sufs[200005];
map<ll,bool> mp;
int res=0,n,m;
void dfs(int dep,int sum,int sy)
{
    if(dep>n)
    {
        if(sy==0)
        {
            res=max(res,sum);
        }
    }
    else
    {
        if(sy>=1) dfs(dep+1,sum&a[dep],sy-1);
        dfs(dep+1,sum,sy);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>5000)
    {
        if(m==n-1)
        {
            pres[1]=a[1];
            sufs[n]=a[n];
            for(int i=2;i<=n;i++) pres[i]=(pres[i-1]&a[i]);
            for(int i=n-1;i>=1;i--) sufs[i]=(sufs[i+1]&a[i]);
            ll ans=sufs[2];
            ans=max(ans,pres[n-1]);
            for(int i=2;i<=n-1;i++) ans=max(ans,pres[i-1]&sufs[i+1]);
            cout<<ans;
            return 0;
        }
        int f=1,f2=1;
        for(int i=1;i<=31;i++) mp[pow(2,i)-1]=1;
        for(int i=1;i<=n;i++)
        {
            if(!mp[a[i]]) f=0;
            if(a[i]!=i-1) f2=0;
        }
        if(f==0||f2==0)
        {
            sort(a+1,a+n+1);
            ll ans=a[n];
            for(int i=n-1;i>=n-m+1;i--) ans=(ans&a[i]);
            cout<<ans;
            return 0;
        }
        else
        {
            ll zd=0;
            for(int i=1;i<=n;i++) zd=max(zd,a[i]);
            if(zd<=4)
            {
                int t[5]={0,0,0,0,0};
                for(int i=1;i<=n;i++) t[a[i]]++;
                if(t[4]>=m)
                {
                    cout<<4;
                    return 0;
                }
                else
                {
                    if(t[3]>=m)
                    {
                        cout<<3;
                        return 0;
                    }
                    else
                    {
                        if(t[3]+t[2]>=m||t[2]>=m)
                        {
                            cout<<2;
                            return 0;
                        }
                        else if(t[1]>=m)
                        {
                            cout<<1;
                            return 0;
                        }
                        else
                        {
                            cout<<0;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(n<=20)
    {
        for(int i=1;i<=n;i++)
        {
            dfs(i,a[i],m);
        }
        cout<<res;
    }
    if(20<n&&n<=2000)
    {
        if(m==1)
        {
            ll zd=0;
            for(int i=2;i<=n;i++) zd=max(zd,a[i]);
            cout<<zd;
        }
        else if(m==2)
        {
            ll ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
        }
        else
        {
            ll ans=a[1];
            for(int i=2;i<=n;i++)
            {
                ans=ans&a[i];
            }
            cout<<ans;
        }
    }
    return 0;
}
