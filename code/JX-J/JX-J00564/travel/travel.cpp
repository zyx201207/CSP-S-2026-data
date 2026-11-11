#include<bits/stdc++.h>
using namespace std;
struct Zuo{
    int num;
    char c;
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    Zuo z1,z2;
    cin>>c1>>s1>>c2>>s2;
    z1.num=(s1[0]-'0')*10+s1[1];
    z2.num=(s2[0]-'0')*10+s2[1];
    z1.c=s1[2];
    z2.c=s2[2];
    if(z1.c=='D')z1.c='E';
    if(z2.c=='D')z2.c='E';
    if(c1==c2){
        cout<<"1";
        if(z1.num==z2.num){
            cout<<"1";
            if(z1.c>='A'&&z1.c<='C'&&z2.c>='A'&&z2.c<='C'||z1.c>='E'&&z1.c<='F'&&z2.c>='E'&&z2.c<='F'){
                cout<<"1";
                if(abs(z1.c-z2.c)==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
