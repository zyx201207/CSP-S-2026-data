#include<bits/stdc++.h>
using namespace std;
const int maxn=500001;
int n,ans=1,l;
long long a[maxn],m;
unsigned long long sum;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    l=1;
    for(int i=2;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>m)
        {
            sum-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}