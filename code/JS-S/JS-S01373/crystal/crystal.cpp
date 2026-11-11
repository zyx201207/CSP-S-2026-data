#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],s[100005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int fa=1,fb=1;
    long long maxn=0,zd,zx;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i) fa=0;
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) fb=0;
    }
    sort(a+1,a+n+1);
    if(fa==1)
    {
        long long cnt=m;
        int num=0,ans=0;
        for(int i=n;i>=1;i--)
        {
            if(cnt>=(a[n]-a[i]))
            {
                num++;
                cnt=cnt-(a[n]-a[i]);
            }
            else
            {
                break;
            }
        }
        cout<<num;
        return 0;
    }
    if(fb==1)
    {
        int t=a[2]-a[1];
        int cnt=m/t,num=0;
        for(int i=n;i>=1;i--)
        {
            if(cnt>=(n-i))
            {
                num++;
                cnt=cnt-(n-i);
            }
            else
            {
                break;
            }
        }
        cout<<num;
        return 0;
    }
    if(n<=5000)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            while(a[i]==a[i+1]) i++;
            long long cnt=m;
            int num=0;
            for(int j=i;j>=1;j--)
            {
                if(cnt>=(a[i]-a[j]))
                {
                    num++;
                    cnt=cnt-(a[i]-a[j]);
                }
                else
                {
                    break;
                }
            }
            ans=max(ans,num);
        }
        cout<<ans;
    }
    return 0;
}
