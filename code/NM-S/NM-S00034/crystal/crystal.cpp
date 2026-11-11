#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll s[N],a[N];
ll n,m,ans1=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        ll md=a[i];
        ll l=0,r=i;
        while(l+1<r){
            ll M=(l+r)/2;
            if((i-M+1)*md-(s[i]-s[M-1])<=m){
                r=M;
            }else{
                l=M;
            }
        }
        ans1=max(ans1,i-r+1);
    }
    cout<<ans1;
    return 0;
}
