#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string c1,s1,c2,s2;
bool check(){
    bool x,y;
    x=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
    y=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
    return x==y;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
        if(s1[0]!=s2[0]||s1[1]!=s2[1]){
            cout<<"000";
            return 0;
        }else cout<<"1";
        if(check()){
            cout<<"1";
        }
        else{
            cout<<"00";
            return 0;
        }
        if(s1[2]-1==s2[2]||s1[2]+1==s2[2])cout<<"1";
        else cout<<"0";
    }
    return 0;
}