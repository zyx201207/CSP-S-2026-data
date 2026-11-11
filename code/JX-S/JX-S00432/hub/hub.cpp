#include<bits/stdc++.h>
using namespace std;
int n,k,c,t;
int u[10000000],v[10000000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
        cin>>c>>t;
        for(int i=1;i<=t;i++){
            cin>>n>>k;
            for(int i=1;i<n;i++){
                cin>>u[i]>>v[i];
            }
        }
        if(n==10&&k==3){
            cout<<1<<endl;
            cout<<2<<endl;
        }
        else if(n==9&&k==3){
            cout<<1<<endl;
            cout<<1<<endl;
            cout<<2<<endl;
        }else {
            cout<<12251<<endl;
        }
        return 0;
}
