#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d,l,n;
    char s,x;
    cin>>a>>c>>s>>b>>d>>x;
    l=(int)s;
    n=(int)x;
    if(a==b){
        cout<<"1"<<" ";
    }
    else{
        cout<<"0"<<" ";
    }
    if(c==d){
        cout<<"1"<<" ";
    }
    else{
        cout<<"0"<<" ";
    }
    if(s=='A' or s=='B' or s=='C'){
        if(x=='A' or x=='B' or x=='C'){
            if(l==n+1 or n==l+1){
                cout<<"1 1";
            }
            else{
                cout<<"1 0";
            }
        }
        else{
            cout<<"0 0";
        }
    }
    else if(s=='D' or s=='F'){
        if(x=='D' or x=='F'){
            cout<<"1 1";
        }
        else{
            cout<<"0 0";
        }
    }
}
