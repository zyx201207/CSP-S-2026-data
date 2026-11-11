#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],s;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)b[i]=a[i]-a[i-1];
    for(int i=0;i<n;i++)
    {
        long long cnt=0,ans=1;
        for(int j=i;m>=cnt&&j>0;j--)
        {
            cnt+=b[j];
            m-=cnt;
            ans++;
        }
        s=max(s,ans);
    }
    cout<<s;
    return 0;
}
