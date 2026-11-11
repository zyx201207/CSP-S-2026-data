#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    int a,b;//pai
    a=(s1[0]-'0')*10+s1[1];
    b=(s2[0]-'0')*10+s2[1];
    char c,d;//lie   abc df
    c=s1[2];
    d=s2[2];
    bool p=false,i=false;

    if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')){
        p=!p;
    }else if((c=='D'||c=='F')&&(d=='D'||d=='F')){
        p=!p;
        i=!i;
    }
    if(a==b){
        cout<<"1";
        if(p){
            cout<<"1";
        }
        else{
            cout<<"00";
            return 0;
        }
    }else{
        cout<<"000";
        return 0;
    }
    if((c=='C'&&d=='D')||(d=='C'&&c=='D')){
        cout<<"0";
        return 0;
    }
    if(c-d==1||c-d==-1||i){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
