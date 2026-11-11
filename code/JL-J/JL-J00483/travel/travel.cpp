#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cxs=0,sxs=0;
    char cxz,sxz;
    string  cr,sr,cx,sx;
    int a=0,b=0,c=0,d=0;
    cin>>cr>>cx>>sr>>sx;
    for(int i=1;i<=3;i++){
        if(0<sx[i]<9){
            sxs=sx[i];
            }
        if('A'<sx[i]<<'Z'){
            sxz=sx[i];
            }
    }
    for(int i=1;i<=3;i++){
        if(0<cx[i]<9){
            cxs=cx[i];
            }
        if('A'<cx[i]<'Z'){
            cxz=cx[i];
            }
    }

    if(cr.size()-1 != sr.size()-1){
       a=0;
       b=0;
       c=0;
       d=0;
        }
    if(cr.size()-1 == sr.size()-1){
        a=1;
        if(cxs==sxs){
            b=1;
            if('A'<=cxz<='C'&&'A'<=sxz<='C' || 'D'<=cxz<='F'&&'D'<=sxz<='F'){
                c=1;
                if(char(cxz+1) == sxz ||char(cxz-1) == sxz ){
                    d=0;
                }
                else{
                    d=1;
                }
            }else{
                c=0;
    }
        }else{
            b=0;
    }
    }else{
        a=0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
