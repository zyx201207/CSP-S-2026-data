#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,a,c;
    cin>>n;
    char b,d;
    if(n==1){
        cin>>a>>b;
        cout<<0;
    }
    if(n==2){
        cin>>a>>b>>c>>d;
        if(b==d){
            cout<<0;
        }
        else if(a>c){
            cout<<c;
        }
        else if(a==c){
            cout<<c;
        }
        else{
            cout<<a;
        }
    }


    }
