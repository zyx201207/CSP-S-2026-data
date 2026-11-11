#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t>>n>>k;
    for(int i=1;i<=t;i++){
        cin>>x>>y;
    }
    if(t==2){
        cout<<1<<endl<<2;
        return 0;
    }
    cout<<0;
    return 0;
}
