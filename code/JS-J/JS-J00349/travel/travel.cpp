#include<bits/stdc++.h>
using namespace std;
//ABCDF
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";//1
    else{
        cout<<"0000";//1234
        return 0;
    }
    if((s1[0]==s2[0])&&(s1[1]==s2[1])) cout<<"1";//2
    else{
        cout<<"000";//234
        return 0;
    }
    if(((s1[2]=='C')&&s2[2]=='D')||((s1[2]=='D')&&(s2[2]=='C'))){
        cout<<"00";
        return 0;
    }
    if((s1[2]<='C')&&(s1[2]<='C')){
        cout<<"1";//3
        if((s1[2]==s2[2]+1)||(s1[2]+1==s2[2])) cout<<"1";//4
        else cout<<"0";//4
    }else if((s1[2]>='D')&&(s2[2]>='D')){
        cout<<"1";//3
        if((s1[2]==s2[2]+2)||(s1[2]+2==s2[2])) cout<<"1";//4
        else cout<<"0";//4
    }else{
        cout<<"00";//34
    }
    return 0;
}
