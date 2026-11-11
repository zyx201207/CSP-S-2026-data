#include<bits/stdc++.h>
using namespace std;
long long m,a[500005];
int n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long d=a[2]-a[1];
    bool flag=0;
    for(int i=2;i<n;i++)
    {
        if(a[i+1]-a[i]!=d)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        for(int i=1;i<=n;i++)
        {
            long long b=i*(i+1)/2;
            if(b*d>m)
            {
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int cnt=i-1;
        long long num=0;
        while(cnt)
        {
            num+=(a[i]-a[cnt]);
            if(num>m)
            {
                ans=max(ans,i-cnt);
                break;
            }
            cnt--;
        }
        ans=max(ans,i-cnt);
    }
    cout<<ans;
    return 0;
}
