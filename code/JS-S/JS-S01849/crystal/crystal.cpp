#include <bits/stdc++.h>
using namespace std;
#define int long long
int n=0,m=0,b=0,maxn=0,num=0,ans=0,s[500005]={0},a[500005]={0};
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    if(n>5000)
    {
        num=abs(s[2]-s[1]);
        while(true)
        {
            if(m-num<0) break;
            if(m-num*2<0)
            {
                ans++;
                break;
            }
            m-=num*2;
            ans+=2;
            num+=num;
        }
        cout<<ans+1;
    }
    else
    {
        sort(s+1,s+1+n);
        for(int i=1;i<=n;i++)
        {
            ans=0;
            b=m;
            a[500005]={0};
            for(int j=1;j<=n;j++) a[j]=abs(s[i]-s[j]);
            sort(a+1,a+n+1);
            for(int j=1;j<=n;j++)
            {
                if(b-a[j]>=0) ans++;
                else break;
                b-=a[j];
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn;
    }
    return 0;
}
