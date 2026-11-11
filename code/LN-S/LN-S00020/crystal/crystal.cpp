#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const __int16_t one=1;
const int N=5e5+10;
ll n,m;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool typeB=true;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[2]-a[1]){
            typeB=false;
            break;
        }
    }
    if(typeB){
        ll d=a[2]-a[1];
        ll t=m;
        ll k=d;
        while(t>=k){
            t-=k;
            k+=d;
        }
        cout<<min(k/d,n);
    }else{
        sort(a+1,a+1+n);
        s[1]=0;
        ll num=0;
        ll k;
        for(ll i=2;i<=n;i++){
            num=one*(a[i]-a[i-1])*(i-1)+one*s[i-1];
            if(num>m){
                k=i-1;
                break;
            }
            s[i]=num;
        }
        cout<<k;
    }

    return 0;
}
