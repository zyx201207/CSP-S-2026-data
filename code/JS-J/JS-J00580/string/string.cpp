#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[100000005];
int a,b,n,last,jq,ans;
char ai;
//int dp[200005];
//struct s
//{
//    int l,r;
//    int t;
//}st[200005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0,js=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>ai;
        for(int j=cnt;j<=cnt+a;j++)
        {
            c[j]=ai;
        }
        cnt+=a;
        /*if(ai==last)
        {
            ++jq;
            st[i-jq].r+=a;
            continue;
        }
        st[i-jq].l=cnt;
        st[i-jq].r=cnt+a;
        st[i-jq].t=ai;
        cnt+=a;
        last=ai;
        dp[++js]=st[i-jq].r;*/
    }
    //cout<<cnt<<endl;
    //for(int i=1;i<=cnt;i++)
    //{
    //    cout<<c[i];
    //}
    //cout<<(cnt+1)/2<<' ';
    for(int i=0;i<=cnt/2;i++)
    {
        if(c[i]!=c[cnt-1-i]) ans++;
    }
    //int ll=1,rr=n;
    //for(int i=1;i<=js;i++)
    //{

    //}
    /*//for(int i=1;i<=cnt/2;i++)
    //{
      //  if(st[ll].l)
    //}
    */
    cout<<ans<<'\n';
}
