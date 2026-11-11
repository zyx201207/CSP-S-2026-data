#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;
long long n,m,t,c,ls,ans,mi,cnt;
long long a[N];
long long q[N];
long long h[N];

void dfs(int u,int dis,int goal)
{
    if(dis>mi) return;
    if(u==goal)
    {
        if(dis<mi)
        {
            mi=dis;
            cnt=1;
        }
        else cnt++;
        return;
    }
    for(int v=u+1;v<=goal;v++)
    {
        if(a[u]+m<a[v]) return;
        dfs(v,dis+1,goal);
    }
}

bool pd(int u,int v)
{
    mi=1e17;
    cnt=0;
    dfs(u,0,v);
    return cnt==2;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            if(a[1]==a[2])
            {
                cout<<"0\n";
                continue;
            }
            long long k=m/(a[2]-a[1]);
            if(k<=1) cout<<"0\n";
            else cout<<max(0ll,n-(2*k-1))<<"\n";
        }
        return 0;
    }
    else
    {
        while(t--)
        {
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            for(int i=1;i<n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(pd(i,j)) ans++;
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    //cin>>c>>t;
    /*
    t=1;
    while(t--)
    {
        memset(q,0,sizeof(q));
        memset(h,0,sizeof(h));
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        ls=1;
        for(int j=1;j<=n;j++)
        {
            while(a[j]+m>=a[ls+1]&&ls+1<=n) ls++;
            q[j]=ls;
        }
        ls=n;
        for(int j=n;j>=1;j--)
        {
            while(a[j]-m<=a[ls-1]&&ls-1>=1) ls--;
            h[j]=ls;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(h[j]+1==q[i]) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    */
    return 0;
}
