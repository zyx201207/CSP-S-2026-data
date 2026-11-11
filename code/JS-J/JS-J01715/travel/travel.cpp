#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";
    if((s1[0]^48)*10+s1[1]!=(s2[0]^48)*10+s2[1]){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";
    if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')){
        cout<<"00"<<endl;
        return 0;
    }
    cout<<"1";
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        cout<<"1"<<endl;
        return 0;
    }
    cout<<"0"<<endl;
    return 0;
}
