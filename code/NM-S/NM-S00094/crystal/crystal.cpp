#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
int main(void)
{
    // crystal
    freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    a.reserve(n+150);
    for(long long i=0;i<n;i++)
    {
        long long t=0;
        cin>>t;
        a.emplace_back(t);
    }
    sort(a.begin(),a.end());
    long long l=0,r=0;
    long long ans=1;
    long long lans=1;
    long long lsum=0;
    while(r<n-1)
    {
        r++;
        if(lsum+(r-l)*(a[r]-a[r-1])<=m)
        {
            lans++;
            lsum+=(r-l)*(a[r]-a[r-1]);
            ans=max(lans,ans);
            // continue;
        }else{
            while(lsum+(r-l)*(a[r]-a[r-1])>m)
            {
                lsum-=a[r-1]-a[l];
                l++;
            }
            lans=r-l+1;
            lsum+=(r-l)*(a[r]-a[r-1]);
            ans=max(lans,ans);
        }
        
    }
    cout<<ans;
    return 0;
}

