#include<bits/stdc++.h>
using namespace std;
string s,s1,c,c1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>c>>c1;
    if(s==c)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[1]==c1[1]&&s1[0]==c1[0])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]>='D'&&c1[2]>='D')||(s1[2]<='C'&&c1[2]<='C')){
            cout<<1;
            if(s1[2]-c1[2]==1||c1[2]-s1[2]==1)cout<<1;
            else cout<<0;
    }
    else cout<<"00";
return 0;
}
