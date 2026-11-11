#include<bits/stdc++.h>
using namespace std;
char e[6];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        e[0]='1';
    }
    else{
        e[0]='0';
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0] && b[1]==d[1]){
        e[1]='1';
    }
    else{
        e[1]+='0';
        cout<<"1000";
        return 0;
    }
    if(((b[2]>='A' && b[2]<='C') && (d[2]>='A' && d[2]<='C')) || ((b[2]>='D' && b[2]<='F') && (d[2]>='D' && d[2]<='F'))){
        e[2]='1';
    }
    else{
        e[2]='0';
        cout<<"1100";
        return 0;
    }
    if((b[2]=='C' && d[2]=='D') || (d[2]=='D' && b[2]=='C')){
        e[3]='0';
    }
    else if((b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D')){
        e[3]='1';
    }
    else{
        if(b[2]==char(int(d[2]+1)) || b[2]==char(int(d[2]-1)) || d[2]==char(int(b[2]+1))|| d[2]==char(int(b[2]-1))){
            e[3]='1';
        }
        else{
            e[3]='0';
        }
    }
    for(int i=0;i<4;i++){
        cout<<e[i];
    }
    return 0;
}
