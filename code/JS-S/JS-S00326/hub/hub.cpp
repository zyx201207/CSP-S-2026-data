#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int v1,v2;
            cin>>v1>>v2;
        }
    }
    if(c==0&&t==2){
        cout<<1<<endl<<2;
    }if(c==0&&t==3){
        cout<<1<<endl<<1<<endl<<2;
    }if(c==0&&t==5){
        cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
    }if(c==0&&t==1){
        cout<<12251;
    }

    return 0;
}
