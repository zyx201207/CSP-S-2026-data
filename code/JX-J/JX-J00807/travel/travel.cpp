#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string c_r,s_r;
    string c_x,s_x;
    cin>>c_r>>s_r>>c_x>>s_x;
    if(c_r==c_x){
        s+='1';
    }else{
        cout<<'0';
        cout<<'0';
        cout<<'0';
        cout<<'0';
        return 0;
    }
    if(s_r[0]==s_x[0] && s_r[1]==s_x[1]){
        s+='1';
    }else{
        s+='0';
        s+='0';
        s+='0';
        cout<<s;
        return 0;
    }
    if(s_r[2]<'D' && s_x[2]<'D' || s_r[2]>'C' && s_x[2]>'C'){
        s+='1';
    }else{
        s+='0';
        s+='0';
        cout<<s;
        return 0;
    }
    if(s_r[2]== 'A' && s_x[2]=='B' ||s_r[2]== 'B' && s_x[2]=='A'||s_r[2]== 'C' && s_x[2]=='B'||s_r[2]== 'B' && s_x[2]=='C' ||s_r[2]== 'D' && s_x[2]=='F'||s_r[2]== 'F' && s_x[2]=='D'){
            s+='1';
            cout<<s;
            return 0;


    }else{
        s+='0';
        cout<<s;
        return 0;
    }

    return 0;
}
