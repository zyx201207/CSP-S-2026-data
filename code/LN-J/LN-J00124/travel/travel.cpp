#include<bits/stdc++.h>
using  namespace std;\
string s1,s2;
string c1,c2;
string s[5] = {"A","B","C","D","E"};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int cx1 = 0,cx2 = 0,zw1 = 0,zw2 = 0;
    string zm1,zm2;
    for(int i = 1;i<=2;i++){
        cx1 += c1[i-1]-'0';
        cx1*=10;
        cx2 += c2[i-1]-'0';
        cx2*=10;
        zw1 = s1[i-1] - '0';
        zw1 *=10;
        zw2 = s2[i-1] - '0';
        zw2 *=10;
    }zm1 = s1[2];
    zm2 = s2[2];
    if(c1==c2){
        cout<<"1";
        if(zw1 == zw2){
            cout<<"1";
            bool z1 = 0,z2 = 0,y1 = 0,y2 = 0;
            for(int i = 0;i<3;i++){
                if(zm1 == s[i]){
                    z1 = i;
                }else if(zm2 == s[i]){
                    z2 = i;
                }
            }for(int i = 3;i<5;i++){
                if(zm1 == s[i]){
                    y1 = i;
                }else if(zm2 == s[i]){
                    y2 = i;
                }
            }if((z1&&z2)||(y1&&y2)){
                cout<<"1";
                if((abs(z1-z2)==1||abs(y1-y2)==1)&&(zm1!="C"&&zm2!="D")&&(zm1!="D"&&zm2!="C")){
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
