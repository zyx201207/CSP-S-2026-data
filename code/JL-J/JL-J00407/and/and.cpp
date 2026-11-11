#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
            ll ans=-11111;
        for(ll i=1;i<=n-1;i++){
            for(ll j=i+1;j<=n;j++){
                    int ii=a[i];
                    int jj=a[j];
                    ii&=jj;
                if(ans<ii) ans=ii;
            }
        }
        cout<<ans;
    }
    if(m==1){
        ll anss=-111111;
        for(ll i=1;i<=n;i++){
            if(a[i]>anss) anss=a[i];
        }
        cout<<anss;
    }
    else{
            ll cnt=1;
    ll num=a[1]&=a[2];
        ll ansss=-11111;
        for(int i=1;i<=n-m+1;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt<m){
                    num&=a[j];
                }
                if(cnt==m){
                    if(ansss<num) ansss=num;
                }
            }
        }
        cout<<num;
    }
    return 0;
}
