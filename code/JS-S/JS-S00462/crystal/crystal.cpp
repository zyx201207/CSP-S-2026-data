#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500009];

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
    long long sum=0;
    int ans=1;
    for(int l=1,r=1;r<=n;r++)
    {
        sum+=(a[r]-a[r-1])*(r-l);
        while(sum>m)
        {
            sum-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}
