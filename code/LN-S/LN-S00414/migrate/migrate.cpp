#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int dp[2000005];
void c1112()
{
    int n,d,a1,a2;
    cin>>n>>d>>a1>>a2;
    for(int i=3;i<=n;i++)
    {
        int k;cin>>k;
    }
    int d1=d/(a2-a1);
    if(d1>=2)
        cout<<max(0ll,n-(2*d1-1))<<endl;
    else
        cout<<0<<endl;
}
void c11()
{
    memset(a,0,sizeof(a));
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int j=1;
    int ans=0;
    for(int i=1;i<=n-3;i++)
    {
        while(a[j]-a[i]<=d&&j<=n)
            j++;
        if(j-i<=2)
            continue;
        int k=j;
        while(a[k]-a[j-3]<=d&&k<=n)
            k++;
        if(a[k]-a[j-2]>d)
            continue;
        int res=0;
        while(a[k]-a[j-2]<=d&&k<=n)
        {
            k++;
            res++;
        }
        while(a[k]-a[k-1]<=d&&a[k+1]-a[k-1]>d)
        {
            k++;
            res++;
            if(k==n)
                break;
        }
        int l=i-1;
        int res2=1;
        while(a[l+1]-a[l]<=d&&a[l+1]-a[l-1]>d)
        {
            l--;
            res2++;
            if(l==1)
                break;
        }
        ans+=res*res2;
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    if((c>=11&&c<=12))
    {
        while(t--)
            c1112();
    }
    while(t--)
        c11();
    return 0;
}
