#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N =2e5;
ll n=0;
struct node{
    ll v;
    char c;
}a[N+5];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].v>>a[i].c;
    }
    ll l=1,r=n,ans=0;
    while(l<r){
        ll mn=min(a[l].v,a[r].v);
        a[l].v-=mn;
        a[r].v-=mn;
        if(a[l].c!=a[r].c){
            ans+=mn;
        }
        if(a[l].v==0){
            l++;
        }
        if(a[r].v==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
