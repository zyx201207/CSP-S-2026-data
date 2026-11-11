
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool q1,q2,q3,q4;
    if(c1[1]==c2[1]&&c1[0]==c2[0]){
        cout<<'1';
        q1=true;
    }
    else{
        cout<<"0000";
        return 0;
    }


    if(q1=true&&(s1[1]==s2[1]&&s1[0]==s2[0])){
        cout<<'1';
        q2=true;
    }
    else{
        cout<<"000";
        return 0;
    }


    if(q2=true&&(s1[2]<'D'&&s2[2]<'D')||(s1[2]>'D'&&s2[2]>'D')){
        cout<<'1';
        q3=true;
    }
    else{
        cout<<"00";
        return 0;
    }


    if(q3 == true&&s1[2]<'D'&&(s1[2]==s2[2]+1||s1[2]==s2[2]-1)){
        cout<<'1';
        q4=true;
    }
    else if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
        cout<<'1';
        q4=true;
    }
    else cout<<'0';
    return 0;
}

