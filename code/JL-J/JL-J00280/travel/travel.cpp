#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    if(s1==s2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(c1[0]==c2[0]&&c1[1]==c2[1])cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>='D'&&c2[2]>='D'))cout<<1;
    else {
        cout<<"00";
        return 0;
    }
    int x=(int)c1[2];
    int y=(int)c2[2];
    if(x<=67){
        if(abs(x-y)==1)cout<<1;
        else cout<<0;
    }else {
        cout<<1;
    }
    return 0;
}
