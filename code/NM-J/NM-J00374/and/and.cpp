#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    ll ma=0; ll t=a[1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        t&=a[i];
    }

    if(m==1) cout<<ma;
    else if(m==2){
        ma=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
    }else if(m==n){
        cout<<t;
    }else{
        cout<<ma;
    }
    return 0;
}


