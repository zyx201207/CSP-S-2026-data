#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long A,B;
    string a,b;
    cin>>A>>a>>B>>b;
    if(A!=B){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(a.substr(0,2)!=b.substr(0,2)){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(!(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'||
       a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F')){
        cout<<"00";
        return 0;
       }
    cout<<1;
    if(a[2]=='F'){
        a[2]='E';
    }
    if(b[2]=='F'){
        b[2]=='E';
    }
    if(abs(a[2]-b[2])!=1){
        cout<<"0";
        return 0;
    }
    cout<<1;
    return 0;
}
