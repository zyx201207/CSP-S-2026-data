#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxx=-1,nn=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxx)maxx=a[i];
        nn=nn&a[i];
    }
    if(m==1){
        cout<<maxx;
    }else if(m==n){
        cout<<nn;
    }else if(m==2){
        ll maxxx=-1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(i==j)continue;
                if(a[i]&a[j]>maxxx)maxxx=(a[i]&a[j]);
            }
        }
        cout<<maxxx;
    }
    return 0;
}//and