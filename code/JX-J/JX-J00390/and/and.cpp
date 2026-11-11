#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        for(long long i=1;i<=n;i++){
            if(i==1) ans = a[i];
            else ans = ans&a[i];
        }
        cout<<ans<<"\n";
        return 0;
    }
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n]<<"\n";
        return 0;
    }
    if(m==2){
        for(long long i=1;i<n;i++)
        {
            ans = a[i]&a[i+1];
            for(long long j=i+1;j<=n;j++)
            {
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
