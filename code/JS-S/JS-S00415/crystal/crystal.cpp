#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500000+500];
int dp[500000+500];
int s[500000+500];
int kl;
int jxd(int k)
{
    int l=0;
    int r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        int op=dp[mid]+mid*(kl-a[mid]);
        if(op>=k)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    //cout << a[1] << endl;
    /*for(int i=1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;*/
    int cnt=0;
    int x=0;
    int sum=0;
    int ans=0;
    s[n]=0;
    for(int i=n-1;i>0;i--)
    {
        if(a[i]==a[i+1])
        {
            s[i]=s[i+1]+1;
        }
        else s[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        sum=sum+(a[i]-x)*cnt;
        //if(sum>m) break;
        dp[i]=sum;
        x=a[i];
        cnt++;
        //out << dp[i] << " ";
    }
    //cout << endl;
    for(int i=n;i>0;i--)
    {
        kl=a[i];
        int root=jxd(dp[i]-m);
        //if(i==24) cout << dp[i]-m << endl;
        ans=max(ans,i-root+s[i]);
    }
    cout << ans << endl;

    return 0;
}