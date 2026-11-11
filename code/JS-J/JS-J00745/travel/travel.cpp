#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,c;
char b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a=s1[0]+s1[1];
    b=s1[2];
    c=s2[0]+s2[1];
    d=s2[2];
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<1;
        if(a!=c){
            cout<<"000";
        }else{
            cout<<1;
            if(b<='C'&&d<='C'){
                cout<<1;
                if(abs(int(b)-int(d))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if(b>='D'&&d>='D'){
                cout<<1;
                if(abs(int(b)-int(d))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }
    }
    return 0;
}
