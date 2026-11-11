#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=500010;
ll n,m;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<n<<" "<<m<<"\n";
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll res=0,l=1,r=1,ans=0;
    for(l=1,r=1;r<n;){
        while(r<n&&res+(r-l+1)*(a[r+1]-a[r])<=m) res+=(r-l+1)*(a[r+1]-a[r]),r++;
        //if(ans<=r-l+1)cout<<l<<" "<<r<<"\n";
        ans=max(ans,r-l+1);
        res-=a[r]-a[l],l++;
    }
    ans=max(ans,r-l+1);
    cout<<ans;
    return 0;
}