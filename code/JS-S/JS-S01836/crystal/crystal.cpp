#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ull ans=0,sum=0;
    for(ull i=1,j=1;j<=n;j++){
        sum+=(a[j]-a[j-1])*(j-i);
        while(sum>m&&i<j)sum-=a[j]-a[i],i++;
        ans=max(ans,j-i+1);
    }
    cout<<ans<<"\n";
    return 0;
}
