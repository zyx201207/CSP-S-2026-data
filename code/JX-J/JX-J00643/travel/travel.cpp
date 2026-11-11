#include<bits/stdc++.h>
using namespace std;
int is(char c){
    if(c=='A'){
        return 1;
    }else if(c=='B'){
        return 2;
    }else if(c=='C'){
        return 3;
    }else if(c=='D'){
        return 4;
    }else if(c=='E'){
        return 5;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,a3,b1,b2,b3;
    string ans="";
    string a,b;
    cin>>a1>>a>>b1>>b;
    a2=int(a[0]-'0')*10+int(a[1]-'0');
    b2=int(b[0]-'0')*10+int(b[1]-'0');
    a3=is(a[2]);
    b3=is(b[2]);
    if(a1==b1){
        if(a2==b2){
            if( (a3<=3&&b3<=3) || (a3>=4&&b3>=4) ){
                if( abs(a3-b3)==1 ){
                    ans="1111";
                }else{
                    ans="1110";
                }
            }else{
                ans="1100";
            }
        }else{
            ans="1000";
        }
    }else{
        ans="0000";
    }
    cout<<ans;
    return 0;
}
