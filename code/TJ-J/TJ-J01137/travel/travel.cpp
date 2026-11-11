
#include<bits/stdc++.h>
using namespace std;
int _(string s){
    return s[2]-'A'+1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==c)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    if(b[0]==d[0]&&b[1]==d[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }

    if((_(b)<=3&&_(b)>=1&&_(d)<=3&&_(d)>=1)||(_(b)<=5&&_(b)>=4&&_(d)<=5&&_(d)>=4))cout<<1;
    else{
        cout<<"00";
        return 0;
    }

    if((_(b)+1==_(d)&&_(b)!=3)||(_(b)-1==_(d)&&_(b)!=4))cout<<1;
    else{
        cout<<"0";
        return 0;
    }

    return 0;
}
