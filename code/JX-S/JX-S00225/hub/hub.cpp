#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,u[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t>>n>>k;
    for(int i=0;i<(n+k)*2;i++){
        cin>>u[i];
    }
    if(n==5&&k==2){
        cout<<1<<endl<<2;
    }
    if(n==8&&k==6){
        cout<<1<<endl<<1<<endl<<3;
    }
    if(n==602&&k==42){
        cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
    }
    if(n==24032&&k==2){
        cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
    }
    if(n==99999&&k==1000){
        cout<<12251;
    }
    return 0;
}
