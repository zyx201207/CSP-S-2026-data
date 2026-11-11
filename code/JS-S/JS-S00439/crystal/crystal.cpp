#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m;
ll a[N],b[N],ans[N];
ll ansn=0,maxn=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    for(ll i=2;i<=n;i++){
        ans[i]=ans[i-1]+b[i]*maxn;
   //     cout<<"zch:"<<ans[i]<<'\n';
        if(ans[i]>m){
            ans[i]-=a[i]-a[i-maxn];
    //        cout<<"pqh:"<<ans[i]<<'\n';
        }else{
            maxn++;
            ansn=ans[i];
            while(i-maxn>=1){
                ansn+=a[i]-a[i-maxn];
            //    cout<<"hbr:"<<i<<' '<<maxn<<' '<<ansn<<'\n';
                if(ansn<=m) maxn++,ans[i]=ansn;
                else break;
            }
        }
    }
    cout<<maxn;
    return 0;
}
