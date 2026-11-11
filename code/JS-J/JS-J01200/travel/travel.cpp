#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
    if(x=='A'||x=='B'||x=='C'){
        if(y=='A'||y=='B'||y=='C')return 1;
        return 0;
    }
    if(y=='D'||y=='F')return 1;
    return 0;
}
bool check2(char x,char y){
    int xx=(x-'A'),yy=(y-'A');
    if(abs(xx-yy)==1)return 1;
    return 0;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(check(s1[2],s2[2])){
                cout<<"1";
                if(check2(s1[2],s2[2]))cout<<"1";
                else cout<<"0";
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
