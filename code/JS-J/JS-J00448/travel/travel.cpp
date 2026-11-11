#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    int x=(a[0]-'0')*10+(a[1]-'0');
    int y=(b[0]-'0')*10+(b[1]-'0');
    if(x==y){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int m=(c[0]-'0')*10+(c[1]-'0');
    int n=(d[0]-'0')*10+(d[1]-'0');
    if(m==n){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
        cout<<1;
    }else if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')){
        cout<<1;
    }else if((c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B')){
        cout<<1;
    }else if((c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
