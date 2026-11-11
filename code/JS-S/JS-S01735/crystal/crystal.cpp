#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    int r=1,ans=0;
    ll sum=0;
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        sum-=(a[i-1]-a[i])*(r-i+1);
        while(sum<=m&&r<=n){
            r++;
            sum+=a[i]-a[r];
        }
        if(sum>m){
            sum-=a[i]-a[r];
            r--;
        }
        ans=max(ans,r-i+1);
        //cout<<r<<" ";
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
