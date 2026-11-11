#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct zfc{
    ll nu;
    string zm;
}a[200005];
ll i,n,len;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].nu>>a[i].zm;
        len+=a[i].nu;
    }
    ll lji=1,ans=0,rji=n,l=0,r=len;
    while(lji<rji){
        if(a[lji].zm!=a[rji].zm){
        //        cout<<1<<'\n';
            ans+=min(a[lji].nu,a[rji].nu);
        }
        if(a[lji].nu==a[rji].nu){
            lji++;
            rji--;
        }else if(a[lji].nu>a[rji].nu){
            a[lji].nu-=a[rji].nu;
            rji--;
        }else{
            a[rji].nu-=a[lji].nu;
            lji++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
