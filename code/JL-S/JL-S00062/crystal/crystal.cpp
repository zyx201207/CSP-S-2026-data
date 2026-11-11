#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i>=3){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                flag=false;
                break;
            }
        }
    }
    if(flag){//为等差数列
            ll d=a[2]-a[1],i;
        for(i=1;i<=n;i++){
            if(d*i*(i+1)/2>m){
                break;
            }
        }
        cout<<i<<endl;
    }
    else{//不是等差
        ll i=1;
        ll ans=0;
        while(i<=n){
            i++;
            if(a[i+1]==a[i]) continue;
            ll j=i;
            ll t=m;
            while(t>=0&&j>0){
                j--;
                if(j==0) continue;
                t=t-a[i]+a[j];
            }
            ans=max(ans,i-j);
        }
        cout<<ans<<endl;
    }
}
