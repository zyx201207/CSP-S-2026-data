#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
    ll a,b;
};
node a[N];
ll n,m;
ll fff(ll x){
    ll ans=0;
    while(x>0){
        x/=2;
        ans++;
    }
    return ans;
}
bool cmp(node a,node b){
    return a.b>b.b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].a;
        a[i].b=fff(a[i].a);
    }
    sort(a+1,a+n+1,cmp);
    ll sum;
    for(ll i=1;i<=m;i++){
        if(i==1){
            sum=a[i].a;
        }
        else{
            sum&=a[i].a;
        }
    }
    cout<<sum;
    return 0;
}
