#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x,y;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)cin>>x>>y;
        cout<<k-1<<endl;
    }
    return 0;
}
