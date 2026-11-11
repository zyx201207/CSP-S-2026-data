#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int rc=10*c1[0]+c1[1];
    int xc=10*c2[0]+c2[1];
    if(rc==xc){
        cout<<1;
    }else{
        cout<<0;
    }
    int rp=10*s1[0]+s1[1];
    int xp=10*s2[0]+s2[1];
    if(rc==xc&&rp==xp){
        cout<<1;

        char r=s1[2],x=s2[2];
        if((r>='A'&&r<='C'&&x>='A'&&x<='C')||(r>='D'&&r<='F'&&x>='D'&&x<='F')){
            cout<<1;
            if((r>='D'&&r<='F'&&x>='D'&&x<='F')||(r>='A'&&r<='B'&&x>='A'&&x<='B')||(r>='B'&&r<='C'&&x>='B'&&x<='C')){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0<<0;
        }
    }else{
        cout<<0<<0<<0;
    }

    return 0;
}
