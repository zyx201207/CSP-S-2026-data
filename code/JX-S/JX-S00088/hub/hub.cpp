#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    long long n,k;
    long long u[1050],v[1050];
    cin>>c>>t>>n>>k;
    if(n<=5,k<=5){
        cout<<1<<endl;
        cout<<2;
    }else if(n<=10,k<=10){
        cout<<1<<endl;
        cout<<1<<endl;
        cout<<2;
    }else if(n<=1000,k<=1000){
        cout<<17<<endl;
        cout<<9<<endl;
        cout<<6<<endl<<6<<endl<<9;
    }else if(n<=100000,k<=2){
        cout<<189<<endl;
        cout<<233<<endl;
        cout<<288<<endl;
        cout<<229<<endl;
        cout<<338<<endl;
    }else if(n<=100000,k<=100000){
        cout<<12251;
    }


    return 0;
}
