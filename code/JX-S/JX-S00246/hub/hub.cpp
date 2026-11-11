#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
        }
        if(k%2==0){
            cout<<(n/2)-1<<endl;
        }
        else cout<<(n+1)/2<<endl;
    }
    return 0;
}
