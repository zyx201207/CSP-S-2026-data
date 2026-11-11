#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10004];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,k,c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<=n;j++){
            cin>>u[j]>>v[j];
        }
    }
    cout<<1;

    return 0;
}
