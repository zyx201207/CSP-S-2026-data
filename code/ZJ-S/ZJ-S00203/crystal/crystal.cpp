#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);

    long long n,m;
    cin>>n>>m;
    long long ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==i)ans++;
    }
    sort(a+1,a+n+1);
    if(ans==n)
    {
        long long h=0;
        a==0;
        for(int i=1;h<=m;++i)
        {
            h+=i;
            a++;
        }
        cout<<min(a+1,n);
    }
    else
    {
        long long mx=0;
        for(int i=1;i<=n;++i)
        {
            long long cut=0;
            long long l=i;
            long long rl=m;
            while(l>=1)
            {
                l--;
                m-=a[i]-a[l];
                if(m<0)break;
                cnt++;
            }
            mx=max(mx,cnt);
        }
        cout<<mx;
    }
    return 0;
}