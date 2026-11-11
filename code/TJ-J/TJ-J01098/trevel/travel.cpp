#include<iostream>
using namespace std;
int main(){
    int r1,r2,x1,x2;
    char x,r;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>r>>x1>>x2>>x;
    int a=0,b=0,c=0,d=0;
    if(r1==x1){
        a=1;
        if(r2==x2){
            b=1;
            if((r=='a'&&x=='b')||(r=='a'&&x=='c')||(r=='b'&&x=='c')||(r=='d'&&x=='f')){
                c=1;
                if(r=='a'&&x=='c'){
                    d=0;
                }
                else{
                    d=1;
                }
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
