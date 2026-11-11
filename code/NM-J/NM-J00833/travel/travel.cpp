#include<bits/stdc++.h>
using namespace std;
char a1[3],b1[4],a2[3],b2[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    int a3=a1[0],a4=a2[0],a5=a1[1],a6=a2[1],b3=b1[0],b4=b2[0],b5=b1[1],b6=b2[1];
    char e1=b1[2],e2=b2[2];
    if((a3==a4)&&(a5==a6)){
        cout<<"1";
        if((b3==b4)&&(b5==b6)){
            cout<<"1";
            if((e1<='C')&&(e2<='C')){
                cout<<"1";
                if(((e1=='A')&&(e2=='B'))||((e1=='B')&&(e2=='A'))||((e1=='C')&&(e2=='B'))||((e1=='B')&&(e2=='C'))){
                    cout<<"1";
                }else cout<<"0";
            }else if((e1>'C')&&(e2>'C')){
                cout<<"11";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
