#include<bits/stdc++.h>
#define forr(i,a,b) for(ll i=a;i<=b;i++)
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=5e5+10;
ll a[N],s[N];
ll n,m;
void so10(){
    ll ans=1;
    for(ll i=n;i>=2;i--){
        ll anss=1;
        ll now=i-1,mm=m;
        // cout<<mm<<endl;
        while(now>=1&&mm>0){
            // cout<<mm<<endl;
            if(a[i]-a[now]<=mm){
                mm-=a[i]-a[now];
                anss++;
                now--;    
            }else{
                break;
            }
        }
        ans=max(ans,anss);
    }
    cout<<ans<<endl;
}
void soB(ll d){
    ll a=m/d*2;
    ll tmp=sqrt(1+4*a);
    ll ans=(tmp-1)/2+1;
    cout<<ans<<endl;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    forr(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool B=1;
    ll d=a[1]-a[2];
    for(ll i=2;i<=n-1;i++){
        if(a[i]-a[i+1]!=d){
            B=0;
            break;
        }
    }
    if(B)soB(-d);
    else{
        so10();
    }
    return 0;
}
//may 75 pts?