#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char x=s1[2],y=s2[2];
    if(x>='A'&&x<='C'){
        if(y>'C'){
            cout<<"00";
            return 0;
        }
        if(x=='B'||y=='B') cout<<11;
        else cout<<10;
    }else{
        if(y<='C'){
            cout<<"00";
            return 0;
        }
        cout<<11;
    }
    return 0;
}
