#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],b[500010],ans=0,flag=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++)
        if(b[i]!=b[i-1])flag=0;
    int t=k,cnt=0,f=0;
    if(flag==1&&b[n]!=0)
    {
        int kk=b[n];
        for(int i=1;kk*i*(i-1)/2<=t;i++)
            ans=i;
        cout<<min(ans,n);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(t<b[i]*cnt)
        {
            if(f<b[i]*(cnt-1))
            {
                ans=max(ans,cnt);
                cnt=0;
                t=k;
                f=0;
            }
            else
            {
                t+=f-b[i]*(cnt-1);
                f=a[i]-a[i-cnt];
            }
        }
        else
        {
            f=a[i]-a[i-cnt];
            t-=b[i]*cnt;
            cnt++;
        }
    }
    cout<<ans;
}
