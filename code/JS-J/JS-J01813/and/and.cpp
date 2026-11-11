#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010][32],f[200010],m,ans[50];
void andd(int t,int k)
{
    int i=1;
    while(t)
    {
        a[k][i]=t%2;
        t/=2;
        i++;
    }
    return;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        andd(t,i);
    }
    for(int i=31;i>=1;i--)
    {
        int t=0;
        for(int j=1;j<=n;j++)
        {
            if(f[j]==1)
            {
                continue;
            }
            t+=a[j][i];
        }
        if(t>=m)
        {
            ans[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]==0&&f[j]==0)
                {
                    f[j]=1;
                }
            }
        }
    }
    int anss=0,w=1;
    for(int i=1;i<=31;i++)
    {
        anss+=ans[i]*w;
        w*=2;
    }
    cout<<anss;
    return 0;
}
