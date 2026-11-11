#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int n,m,a[N],cnt[N][N],ans;
bool vis;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)
            {
                cnt[i][j]=0;
            }
            else
            {
                cnt[i][j]=abs(a[i]-a[j]);
            }
        }
    }
    for(int i=1;i<=n-2;i++)
    {
        if(cnt[i][i+1]!=cnt[i+1][i+2])
        {
            vis=1;
        }
    }
    if(!vis)
    {
        int num=cnt[1][2],sum=0,ans=1;
        for(int i=1;i<=n;i++)
        {
            if(sum+num*i<=m)
            {
                sum+=num*i;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            //cout<<j<<":\n";
            int num=0,sum=0;
            for(int i=1;i<=j;i++)
            {
                if(num+cnt[i][j]<=m)
                {
                    num+=cnt[i][j];
                    sum++;
                }
                else
                {
                    ans=max(ans,sum);
                    num=cnt[i][j];
                    sum=1;
                    if(num<=m)
                    {
                        ans=max(ans,sum);
                    }
                }
                if(i==j)
                {
                    ans=max(ans,sum);
                }
                cout<<num<<" "<<sum<<" "<<ans<<" \n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
