#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0;
    int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
inline void cou(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        cou(x/10);
    }
    putchar(x%10+'0');
}
ll n,m;
vector<ll> a;
vector<ll> ch;
int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x=read();
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        ch.push_back(a[i+1]-a[i]);
    }
    bool f=1;
    ll chh=a[1]-a[0];
    for(int i=1;i<ch.size()-1;i++){
        ll chaa=ch[i+1]-ch[i];
        if(chaa!=chh){
            f=0;
            break;
        }
    }
    if(f){
        for(int i=0;i<n;i++){
            ll sum=i*(i-1)/2*chh;
            if(sum>m){
                cou(1ll*(i-1)*(i-2)/2*chh);
                return 0;
            }
        }
    }
    ll maxn=LLONG_MIN;
    for(ll i=0;i<n;i++){
        ll mst=1,mm=m;
        for(int j=i-1;j>=0;j--){
            int cha=a[i]-a[j];
            if(cha>mm){
                break;
            }
            else{
                mm-=cha;
                mst++;
            }
        }
        maxn=max(maxn,mst);
    }
    cou(maxn);
    return 0;
}
