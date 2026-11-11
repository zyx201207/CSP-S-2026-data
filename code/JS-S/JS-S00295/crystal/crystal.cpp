#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0;
int a[500001],c[500001];
bool ce1315=1,ce1618=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            ce1315=0;
        }
    }
    int x=a[2]-a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=x)
        {
            ce1618=0;
        }
    }

    if(ce1315)
    {
        int cnt=1;
        while(1)
        {
            if(m-cnt<0)
            {
                break;
            }
            m-=cnt;
            cnt++;
        }
        cout<<min(cnt,n);
        return 0;
    }

    if(ce1315==0 && ce1618==1)
    {
        int cnt=1;
        while(1)
        {
            if(m-x*cnt<0)
            {
                break;
            }
            m-=cnt*x;
            cnt++;
        }
        cout<<min(cnt,n);
        return 0;
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int cnt=1;
        for(int j=i+1;j<=n;j++)
        {
            if(m-cnt*(a[j]-a[j-1])<0)
            {
                break;
            }
            m-=cnt*(a[j]-a[j-1]);
            cnt++;
        }
        ans=max(cnt,ans);
    }
    cout<<ans;

    return 0;
}
