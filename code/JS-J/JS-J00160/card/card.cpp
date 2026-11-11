#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==2){
        if(a[n]==1){
            cout<<2<<" ";
            if(a[n-1]==2)cout<<1;
            else cout<<0;
        }
        else {
            if(a[n-1]==1)cout<<1<<" ";
            else cout<<0<<" ";
            cout<<2<<" ";
        }
    }
    else {
        for(int i=1;i<=n;i++){
            if(a[i-1]!=a[i])cout<<i<<" ";
        }
    }
    return 0;
}
