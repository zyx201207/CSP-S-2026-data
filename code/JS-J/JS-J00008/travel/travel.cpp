#include<bits/stdc++.h>
using namespace std;
string ri,rw,xi,xw;
char cr,cx;
int num(string s){
    int res=0;
    res=(s[0]-'0')*10+s[1]-'0';
    return res;
}
int main(){
    freopen("travel2.in","r",stdin);
    freopen("travel2.out","w",stdout);
    cin>>ri>>rw>>xi>>xw;
    cr=rw[2];
    cx=xw[2];
    if(num(ri)==num(xi)){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(num(rw)==num(xw)){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((cr=='A'&&cx=='B')||(cr=='A'&&cx=='C')||(cr=='C'&&cx=='B')||(cr=='B'&&cx=='C')||(cr=='B'&&cx=='A')||(cr=='C'&&cx=='A')||(cr=='D'&&cx=='F')||(cr=='F'&&cx=='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((cr=='A'&&cx=='C')||(cr=='C'&&cx=='A')){
        cout<<0;
    }else{
        cout<<1;
    }
    return 0;
}
