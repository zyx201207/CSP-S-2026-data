#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    string c1,c2,s1,s2,s11="",s21="";
    cin>>c1>>s1>>c2>>s2;
    s11+=s1[0];
    s11+=s1[1];
    s21+=s2[0];
    s21+=s2[1];
    if(c1==c2){
        cout<<1;
        if(s11==s21){
            cout<<1;
            if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='E'&&s1[2]<='F')&&(s2[2]>='E'&&s2[2]<='F'))){
                cout<<1;
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='E'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='E')){
                    cout<<1;
                }
                else{
                    cout<<0;
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
