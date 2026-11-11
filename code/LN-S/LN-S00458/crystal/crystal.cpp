
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    ll j=1,t=0;
    sort(a+1,a+n+1);
    for(int i = 2;i<=n;i++){
        t+=(i-j)*(a[i]-a[i-1]);
        while(t>m){
            t-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans<<"\n";
    return 0;
}
