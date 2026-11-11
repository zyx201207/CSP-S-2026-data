#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int num1=int(s1[2]-'A')+1;
    int num2=int(s2[2]-'A')+1;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(num1==1){
                if(num2==2) cout<<"11";
                if(num2==3) cout<<"10";
                if(num2==4||num2==5) cout<<"00";
            }else if(num1==2){
                if(num2==1||num2==3) cout<<"11";
                if(num2==4||num2==5) cout<<"00";
            }else if(num1==3){
                if(num2==2) cout<<"11";
                if(num2==1) cout<<"10";
                if(num2==4||num2==5) cout<<"00";
            }else if(num1==4){
                if(num2==5) cout<<"11";
                if(num2==3) cout<<"00";
                if(num2==1||num2==2) cout<<"00";
            }else if(num1==5){
                if(num2==4) cout<<"11";
                if(num2==3) cout<<"00";
                if(num2==1||num2==2) cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
