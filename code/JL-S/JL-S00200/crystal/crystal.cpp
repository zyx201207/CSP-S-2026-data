#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;

ll n,m;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&(a[i]-a[i-1]!=a[i-1]-a[i-2])) flag=0;
    }
    sort(a+1,a+1+n);

    if(flag){
        ll gc=a[2]-a[1];
        ll ned=0,cnt=0;
        for(ll i=2;i<=n;i++){
            if(ned+(i-1)*gc<=m){
                ned+=(i-1)*gc;
                cnt=i;
            }else{
                break;
            }
        }
        cout<<cnt;
    }else {
        ll ans=1;
        for(ll i=2;i<=n;i++){
            ll sum=0;
            ll cnt=1;
            for(int j=i-1;j>=1;j--){
                if(sum+a[i]-a[j]==m){
                    ans=max(ans,cnt+1);
                    break;
                }else if(sum+a[i]-a[j]>m){
                    ans=max(ans,cnt);
                    break;
                }else{
                    cnt++;
                    sum+=a[i]-a[j];
                }
            }
        }
        cout<<ans;
    }





    return 0;

}
