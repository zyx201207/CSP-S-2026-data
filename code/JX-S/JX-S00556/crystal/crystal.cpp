#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100050],b[100050],m,n,mi=0,mn=0;
inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-1') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
 int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n=read(),m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
        if(mn<a[i]) mn=a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        b[i]=mn-a[i];
        mi+=b[i];
    }
    if(mi<=m){
        printf("%lld",n);
        return 0;
    }
    ll sum=0,id=n;
    for(ll j=mn;j>=1;j--){
        ll ans=0,it=0;
        for(ll i=id;i>=1;i--){
            if(b[i]-1<0) id--;
            else{
                b[i]--;
                mi--;
            }
            if(mi>m){
                it=id-(i+1);
                continue;
            }
        }
        if(mi<=m) it=id;
        sum=max(it,sum);
        if(j<=sum) continue;
    }
    printf("%lld",sum);
    return 0;
}
