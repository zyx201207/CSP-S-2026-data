#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000005],m,b[1000005],ans,ansf;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=2;i--)
    {
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            b[j]=abs(a[j]-a[i]);
        }
        sort(b+1,b+n+1);
        int t=0,c=0;
        while(true)
        {
            c++;
            t+=b[c];
            if(t>m)
            {
                t-=b[c];
                break;
            }
            ans++;
        }
        ansf=max(ansf,ans);
    }

    cout<<ansf;
}
