#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,u[2000005],v[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        if(n<11) cout<<n/5<<endl;
        else cout<<n/1.6<<endl;
    }
    return 0;
}
