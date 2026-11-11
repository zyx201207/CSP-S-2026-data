#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n-k<=2) cout<<1<<"\n";
        else if(n<=6) cout<<1<<"\n";
        else if(n==7&&k>=3) cout<<1<<"\n";
        else if(n==8&&k>=3) cout<<1<<"\n";
        else if(n==9&&k>=3) cout<<1<<"\n";
        else if(n==10&&k>=4) cout<<1<<"\n";
        else cout<<2<<"\n";
    }
    return 0;
}
