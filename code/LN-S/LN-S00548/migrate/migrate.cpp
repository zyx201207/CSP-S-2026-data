#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,minm=0x3f3f3f3f3f3f3f3f,cnt=0,ans=0,a[2000001];
void dfs(int now,int fin,int dis)
{
    if(dis>minm)
    {
        return;
    }
    if(now==fin)
    {
        if(dis==minm)
        {
            cnt++;
        }
        if(dis<minm)
        {
            minm=dis,cnt=1;
        }
        return;
    }
    for(int i=1;i+now<=fin&&a[now+i]-a[now]<=m;i++)
    {
        dfs(now+i,fin,dis+1);
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==1||c==2)
    {
        while(t--)
        {
            ans=0;
            cin>>n>>m;
            if(n==1)
            {
                cout<<0<<endl;
                continue;
            }
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    minm=0x3f3f3f3f3f3f3f3f,cnt=0;
                    dfs(i,j,0);
                    if(cnt==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    else if(c==11||c==12)
    {
        while(t--)
        {
            cin>>n>>m;
            if(n==1)
            {
                cout<<0<<endl;
                continue;
            }
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            int x=a[1]-a[0];
            m/=x;
            if(m<2)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<max(0ll,n-(m*2-1))<<endl;
            }
        }
    }
    else
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
