#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],cnt[N],b[N];
int add(long long base)
{
    long long left=m;
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    int sum=0;
    for(int i=n;i>=1;i--)
    {
        if(b[i]<base)
        {
            if(left+b[i]-base>=0)
            {
                left-=(base-b[i]);
                b[i]=base;
            }else{
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==base)
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    long long x=0,s=0;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        cnt[a[i]]++;
        s+=a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        x=max(cnt[a[i]],x);
    }
    if(m==0)
    {
        cout<<x;
        return 0;
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(m>a[n]*n-s)
    {
        cout<<n;
        return 0;
    }
    int ans=0;
    for(long long i=a[1]+1;i<=a[n];i++)
    {
        ans=max(add(i),ans);
    }
    cout<<ans;
    return 0;
}
