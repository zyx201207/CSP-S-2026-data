#include <bits/stdc++.h>
using namespace std;

string s1,c1,s2,c2;
int line1=0,line2=0;
char a1,a2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    line1+=(c1[0]-'0')*10;
    line2+=(c2[0]-'0')*10;
    line1+=(c1[1]-'0');
    line2+=(c2[1]-'0');
    a1=c1[2];
    a2=c2[2];
    if(s1==s2){
        cout<<"1";
        if(line1==line2){
            cout<<"1";
            if((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D')){
                cout<<"1";
                if((a1-a2==-1||a1-a2==1)||(a1=='D'&&a2=='F')||(a1=='F'&&a2=='D')){
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
