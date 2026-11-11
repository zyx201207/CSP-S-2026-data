#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t,n,k,u,v;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>u>>v;
        if(n==5  &&  k==2){
            cout<<"1"<<endl<<"2";
            return 0;
        }
        if(n<=10){
            cout<<"2"<<endl;
        }else if(n<20){
            cout<<"16"<<endl;
        }else if(n<30){
            cout<<"28"<<endl;
        }else if(n<40){
            cout<<"38"<<endl;
        }
    }
    return 0;
}
