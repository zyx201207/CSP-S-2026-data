#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string rseat,xseat,rseat1,xseat1;
cin>>rseat>>rseat1>>xseat>>xseat1;
string r1,x1;
char r2,x2;
for(int i=0;i<rseat1.size()-1;i++){
        r1+=rseat1[i];
x1+=xseat1[i];
}
r2=rseat1[2];
x2=xseat1[2];
int xianglin=x2-r2;

if(rseat==xseat){

    if(r1==x1){

        if((r2>='A'&& r2<='C' && x2>='A'&& x2<='C') || (r2>='D' && r2<='F' && x2>='D' && x2<='F')){

            if(xianglin==1 || xianglin==-1)
                cout<<1111;
            else cout<<1110;
        }
        else cout<<1100;
    }
    else cout<<1000;
}
else {cout<<0<<0<<0<<0;}
return 0;}
