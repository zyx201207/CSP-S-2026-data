#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000005]={},D;
ll j[5005][5005]={};
ll c;
ll read(){
    ll ans=0;
    char c;
    c=getchar_unlocked();
    while(c<'0'||c>'9')c=getchar_unlocked();
    while(c>='0'&&c<='9')ans=ans*10+(c-'0'),c=getchar_unlocked();
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll t;
    c=read(),t=read();
    while(t--){
        ll n=read();
        D=read();
        for(int i=0;i<n;i++)x[i]=read();
        if(c<=10){
            ll ans=0;
            for(int len=1;len<=n;len++){
                for(ll l=0;l+len-1<n;l++){
                    if(len<=D+1){j[l][len]=0;continue;}
                    ll L=0,r=n-1,mid;
                    while(r-L>1){
                        mid=(L+r)/2;
                        if(x[l+len-1]-x[mid]<=D)r=mid;
                        else L=mid;
                    }
                    if(x[l+len-1]-x[L]<=D)r=L;
                    j[l][len]=j[r][l+len-r]+1;
                    if(len+l-1-r>=2&&((len+l-1-r==2&&j[l][l+len-r]==j[l][l+len-r-1])||(len+l-r-1!=2&&j[l][l+len-r]==j[l][l+len-r-1]&&j[l][l+len-r]!=j[l][l+len-r-2]))){
                        ans++;
                    }
                }
            }
            cout << ans << '\n';
        }else cout << "0\n";
    }
    return 0;
}
