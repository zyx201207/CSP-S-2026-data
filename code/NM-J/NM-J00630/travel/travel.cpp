#include<bits/stdc++.h>
using namespace std;
char s1,s2;
int a1,a2,b1,b2,a3,a4,b3,b4;
int main(){
freopen("travel","r",stdin);
freopen("travel","w",stdout);
scanf("%d%d%c%d%d%c",&a1,&a2,&s1,&b1,&b2,&s2);
int t=0,h=0;
if(a1==b1){
    cout<<"1";
    if(a2==b2){
        cout<<"1";
        if(((s1=='D'||s1=='F')&&(s2=='D'||s2=='F'))||((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C'))){
            cout<<"1";
            if(((s1=='A'||s1=='B')&&(s2=='A'||s2=='B'))||((s1=='B'||s1=='C')&&(s2=='B'||s2=='C'))||((s1=='D'||s1=='F')&&(s2=='D'||s2=='F'))){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }else{
            cout<<"00";
        }
    }else{
        cout<<"000";

    }
}else{
    cout<<"0000";

}
return 0;
}
