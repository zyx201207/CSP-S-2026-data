#include <bits/stdc++.h>
using namespace std;
int c1,c2,p=0;
string s1,s2;
char s11,s12,s13,s21,s22,s23;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0";
        cout<<"0";
        cout<<"0";
        cout<<"0";
        return 0;
    }
    for(char a:s1){
        p++;
        if(p==1){
            s11=a;
        }
        if(p==2){
            s12=a;
        }
        if(p==3){
            s13=a;
        }
    }
    p=0;
    for(char a:s2){
        p++;
        if(p==1){
            s21=a;
        }
        if(p==2){
            s22=a;
        }
        if(p==3){
            s23=a;
        }
    }
    if(s11==s21&&s12==s22){
        cout<<"1";
        if((s13=='A'&&s23=='B')||(s13=='A'&&s23=='C')||(s13=='B'&&s23=='A')||(s13=='B'&&s23=='C')||(s13=='C'&&s23=='A')||(s13=='C'&&s23=='B')||(s13=='D'&&s23=='F')||(s13=='F'&&s23=='D')){
            cout<<"1";
            if((s13=='A'&&s23=='B')||(s13=='B'&&s23=='A')||(s13=='B'&&s23=='C')||(s13=='C'&&s23=='B')||(s13=='D'&&s23=='F')||(s13=='F'&&s23=='D')){
                cout<<"1";
                return 0;
            }
            else{
                cout<<"0";
                return 0;
            }
        }
        else{
            cout<<"0";
            cout<<"0";
        }
    }
    else{
        cout<<"0";
        cout<<"0";
        cout<<"0";
    }
    return 0;
}
