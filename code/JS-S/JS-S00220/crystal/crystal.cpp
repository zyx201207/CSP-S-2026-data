#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,ans,a[N],sum[N];
bool check(ll cur,ll p){
    if(sum[cur]-sum[p-1]+m>=(cur-p+1)*a[cur]) return true;
    else return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n;i++){
        ll lft=1,rgt=i-1;
        ll tmp=0;
        while(lft<=rgt){
            ll mid=(lft+rgt)/2;
            if(check(i,mid)){
                tmp=mid;
                rgt=mid-1;
            }
            else lft=mid+1;
        }
        ans=max(ans,i-tmp+1);
    }
    cout<<ans;
    return 0;
}
