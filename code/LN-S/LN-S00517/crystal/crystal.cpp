#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long f[N],c[N],ans;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m;
cin>>n>>m;
long long a[n+1];
for(int i=0;i<=n-1;i++)
    cin>>a[i];
sort(a,a+n);
long long p=0,q=0;
for(int i=0;i<=n-1;i++)
    {
    p=0,q=0;
    for(int j=i-1;j>=0;j--)
        {
        p+=(a[i]-a[j]);
        q++;
        if(p>m)
            {
            break;
            }
        ans=max(ans,q);
        }
    }
cout<<ans+1;
return 0;
}
