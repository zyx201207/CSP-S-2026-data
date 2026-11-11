#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,c="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        c=c+'1';
        if(int((s1[0]-'0')*10+(s1[1]-'0'))==int((s2[0]-'0')*10+(s2[1]-'0'))){
            c=c+'1';
            if(int(s1[2]-'A'+1)<=3&&int(s2[2]-'A'+1)<=3||int(s1[2]-'A'+1)>3&&int(s2[2]-'A'+1)>3){
                c=c+'1';
                if(int(s1[2]-'A'+1)-int(s2[2]-'A'+1)==1||int(s2[2]-'A'+1)-int(s1[2]-'A'+1)==1){
                    c=c+'1';
                }else{
                    c=c+'0';
                }
            }else{
                c=c+"00";
            }
        }else{
            c=c+"000";
        }
    }else {
        c=c+"0000";
    }
    cout<<c;
    return 0;
}
