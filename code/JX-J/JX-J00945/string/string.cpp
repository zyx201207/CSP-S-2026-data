#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct tch{
    ll num;
    char ch;
}rc[290000];
ll min(ll a,ll b){
    if(a>b){
        return b;
    }else{
        return a;
    }
    return 0;
}
void solve(){
    ll n,temp1,temp2,sum=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>rc[i].num>>rc[i].ch;
    }
    ll l=1,r=n;
    while(l<r){
        temp1=rc[l].num,temp2=rc[r].num;
        rc[l].num-=min(temp1,temp2);
        rc[r].num-=min(temp1,temp2);
        if(rc[l].ch!=rc[r].ch){
            sum+=min(temp1,temp2);
        }
        if(rc[l].num==0){
            l++;
        }else if(rc[r].num==0){
            r--;
        }
    }
    cout<<sum;
    return ;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
