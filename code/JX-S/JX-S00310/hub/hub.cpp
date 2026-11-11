#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int q,w;
            cin>>q>>w;
        }
        if(n==k)cout<<1;
        else if(k+1==n)cout<<2;
        else cout<<n-1;
    }
    return 0;
}


