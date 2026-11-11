#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t,n,k,u,v;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++) cin>>u>>v;
        n=n/2+1;
        cout<<(n+3-k)/3<<endl;
    }



    return 0;
}
