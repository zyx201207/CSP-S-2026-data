#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>a>>m>>b;
    if(n!=m){
        cout<<"0000";
        return 0;
    }else{
        cout<<1;
    }
    char a1,b1;
    a1=a[2];
    b1=b[2];
    int a2,b2;
    a2=(a[0]-'0')*10+(a[1]-'0');
    b2=(b[0]-'0')*10+(b[1]-'0');
    if(a2==b2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(a1<='C'&&b1<='C'){
        cout<<1;
    }else if(a1>='D'&&b1>='D'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(a1+1==b1&&a1+1!='D'||a1-1==b1&&a1-1!='C'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
