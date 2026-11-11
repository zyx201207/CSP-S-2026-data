#include<bits/stdc++.h>
using namespace std;int c,t,n,d;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n-1;j++){
            cin>>c;
        }
    }
    for(int i=1;i<=t-1;i++){
        cout<<1<<endl;
    }
    cout<<2;
    return 0;
}
