#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN=5e5+10;
ll n,m,ans=0;
ll a[MN],b[MN];

ll read(){
    ll f=1,res=0;
    char ch; ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar_unlocked();
    }
    return res*f;
}



int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(); m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++){
        while(ans<i){
            if((ans)*a[i]-(b[i-1]-b[i-(ans+1)])>m) break;
            ans++;
        }
    }
    cout<<ans<<endl;


    return 0;
}