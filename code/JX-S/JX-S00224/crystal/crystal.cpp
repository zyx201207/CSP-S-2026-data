#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+15;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll a[N],n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<5000){
        for(int i=2;i<n;i++){
            ll cnt=1,x=m;
            for(int j=i-1;j>=1;j--){
                x-=(a[i]-a[j]);
                if(x>=0) cnt++;
                else break;
            }ans=max(ans,cnt);
        }cout<<ans;
    }else{
        for(int i=n;;i--){
            m-=(a[i]-a[i-1]);
            if(m>=0) ans++;
            else break;
        }cout<<ans;
    }
    return 0;
}
