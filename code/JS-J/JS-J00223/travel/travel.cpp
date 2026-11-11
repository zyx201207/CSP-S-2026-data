#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1(char x){
    if(x=='A'||x=='B'||x=='C')return 0;
    else return 1;
}
int f2(char x){
    if(x=='A')return 1;
    if(x=='B')return 2;
    if(x=='C')return 3;
    if(x=='D')return 5;
    if(x=='F')return 6;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(f1(s1[2])==f1(s2[2])){
                cout<<1;
                if(abs(f2(s1[2])-f2(s2[2]))==1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
