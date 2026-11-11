#include<bits/stdc++.h>
using namespace std;
long long dp[2000006][2],x[2000006],tr[2000006][2],n,d,l=0,c,t;
void add(long long x1,long long k,long long o)
{
    while(k<=n)
    {
        tr[k][o]+=x1;
        k+=k&(-k);
    }
    return;
}
long long query(long long k,long long o)
{
    long long res=0;
    while(k)
    {
        res+=tr[k][o];
        k-=k&(-k);
    }
    return res;
}
void solve()
{
    cin>>n>>d;
    l=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    x[0]=-4000000000000000000;
    //cout<<x[0]<<"\n";
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        while(l<i && x[l]+d<x[i])
        {
            if(l>=1)
            {
                add(dp[l][0],l,0);add(dp[l][1],l,1);
            }
            l++;
        }
        dp[i][0]=i-l+1;
        //cout<<i<<"\n";
        long long x1,x2,l1,r1;
        if(i-l>=2)
        {
            x1=x[l],x2=x[l+1];
            r1=lower_bound(x+1,x+l,x[l+2]-d)-x-1;
            l1=lower_bound(x+1,x+l,x1-d)-x;
            //cout<<l1<<" "<<r1<<" ";
            if(l1<=r1 && l1!=0)dp[i][1]+=query(r1,0)-query(l1-1,0);
        }
        if(i-l>=1)
        {
            x1=x[l];
            r1=lower_bound(x+1,x+l,x[l+1]-d)-x-1;
            l1=lower_bound(x+1,x+l,x1-d)-x;
            //cout<<l1<<" "<<r1<<" ";
            if(l1<=r1 && l1!=0)dp[i][1]+=query(r1,1)-query(l1-1,1);
        }
        //cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
        ans+=dp[i][1];
        //cout<<"\n";
    }
    for(long long i=0;i<=n;i++)
    {
        tr[i][0]=tr[i][1]=0;
        dp[i][0]=dp[i][1]=0;
    }
    cout<<ans<<"\n";
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    //cout<<c<<" "<<t<<"\n";
    while(t--)
    {
        solve();
    }
    return 0;
}
