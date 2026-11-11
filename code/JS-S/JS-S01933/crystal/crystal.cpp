#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500005],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    int pos=1;
    ll sum=0;
    for(int i=1;i<=n;i++){
        while(sum>m){
            sum-=(a[i]-a[pos]);
            pos++;
        }
        ans=max(ans,i-pos+1);
        if(i<n)sum+=(a[i+1]-a[i])*(i-pos+1);
    }
    cout<<ans<<'\n';
    return 0;
}