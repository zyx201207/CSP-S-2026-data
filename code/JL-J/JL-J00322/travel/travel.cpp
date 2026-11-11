#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,n,b,m;
    cin>>a>>n>>b>>m;
    if(a==b){
        if(a!="01"&&a!="016"){
            cout<<1;

        }else{
            cout<<0;
        }
        if(n==m){
            cout<<0;
        }else{
            cout<<1;
        }
        if(m!=n){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    if(n!=m){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
