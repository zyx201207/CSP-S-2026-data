#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int N = 50005;
typedef long long ll;
ll m;
ll n,sum,ans=-1e4;
ll a[N];
bool check(int x){
    if(a[x] == a[x+1])return true;
        else return false ;
}
void f(ll x,ll l,ll d ){//l是此时个数，结果l一定>=2;但初始值为1.d即为m
    if(check (x) == 1){
            f(x+1,l+1,d);
    }else{
    if( x== n && d != 0 &&d%l == 0){
        ans=max(l,ans);
     return ;
    }
    //边界


    if(d==0) {
    ans = max(ans,l);
    return ;
    }
    ll t=(a[x+1]-a[x])*l;
    if(d-t >=0)f(x+1,l+1,d-t);
    if(d-t<0)ans=max(ans,l) ;
}
}

int main(){
    freopen(crystal.in,"r",stdin);
    freopen(crystal.out,"w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort (a+1,a+n+1);
    for(int i=1;i<n;i++){
        f(i,1,m);
    }
    cout<<ans;
}


