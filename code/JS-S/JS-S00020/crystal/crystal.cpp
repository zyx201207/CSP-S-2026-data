#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N],pre[N];
ll n,m;
bool check(ll z,ll y){
    ll zong=pre[y]-pre[z-1];
    ll ying=a[y]*(y-z+1);
    //cout<<"awa "<<zong<<' '<<ying<<endl;
    return m>=ying-zong;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<-1<<endl;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i;
        ll jg=1;
        while(l<=r){
            ll mid=(l+r)/2;
            //cout<<mid<<' ';
            if(check(mid,i)){
                jg=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        //cout<<' '<<jg<<endl;
        ans=max(ans,i-jg+1);
    }
    cout<<ans<<endl;
    return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
