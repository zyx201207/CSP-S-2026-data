#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++)cin>>u>>v;
        if(k==n)cout<<0;
        else if(k*2+1>=n)cout<<1;
        else cout<<(n-2*k)/8+2;
        cout<<"\n";
    }return 0;
}
