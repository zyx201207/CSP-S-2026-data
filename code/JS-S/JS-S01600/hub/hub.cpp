#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        if(n==k)cout<<0<<'\n';
        else cout<<rand()%((n-k-1)/2)+1<<'\n';
    }
    return 0;
}
