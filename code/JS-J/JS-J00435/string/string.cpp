#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll n,len,p,ans;
char tmp;
ll s[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>p>>tmp;
        s[i]=p;
        c[i]=tmp;
        len+=p;
    }
   ll l=1,r=len;
   ll x=1,y=n;
   while(l<r){
        ll t=min(s[x],s[y]);
        if(l+t>=r-t)t=1;
        if(c[x]!=c[y])ans+=t;
        l+=t,r-=t;
        s[x]-=t,s[y]-=t;
        if(s[x]<=0)x++;
        if(s[y]<=0)y--;
   }
    cout<<ans;

    return 0;
}
