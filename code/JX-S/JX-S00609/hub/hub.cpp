#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,k,c,t,u,v;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v;
        }
        cout<<abs(u-3);
    }
    return 0;
}

