#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N],ct[N],dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
        b[i]=a[i]-a[i-1];
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(i*(i+1)*b[2]<=2*m)
            ans=i;
        else
            break;
    }
    if(cnt==(a[1]+a[n])*n/2)
    {
        cout<<ans+1;
        return 0;
    }
    ans=0;
    int q=0,mr=1;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int ww=ct[i-1]+(dp[i-1]+1)*b[i];
        q+=b[i];
        if(ww<=m)
            dp[i]=dp[i-1]+1,ct[i]=ww;
        else
        {
            while(mr<i and q>=0 and ww>m)
            {
                ww-=q;
                q-=b[mr+1];
                mr++;
            }
            dp[i]=i-mr;
            ct[i]=ww;
        }
        ans=max(ans,dp[i]);
        //cnt=0;
        //int ccnt=0,w=0;
        //for(int j=i-1;j>=1;j--)
        //{
        //    ccnt+=w+b[j+1];
        //    w+=b[j+1];
        //    if(ccnt<=m)
        //        cnt++;
        //    else
        //       break;
        //}
        //if(cnt>ans)
        //    cout<<i<<' '<<w<<' '<<ccnt<<' '<<cnt<<endl;
        //ans=max(ans,cnt);
    }
    cout<<ans+1;
    return 0;
}
