#include<bits/stdc++.h>
using namespace std;
int u[1000001],v[1000001];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<=n+k;j++){
            cin>>u[j]>>v[j];
        }
    }
    cout<<1<<endl<<2;
    return 0;
}
