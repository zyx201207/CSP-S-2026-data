#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100009
    ll n,m,a[maxn],p=0,t=1;
bool cmp(ll x,ll y){
    return x<y;
}
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ll mid=n/2+1;
    for(ll i=1;i<=n;i++){
        if(a[i]<a[mid]){
            a[i]+=a[mid]-a[i];
            p++;
            if(p>=m){
                break;
            }
        }
    }
    for(ll i=2;i<=n;i++){
        if(a[i]==a[1]){
            t++;
        }
    }
    cout<<t<<'\n';
    return 0;
}