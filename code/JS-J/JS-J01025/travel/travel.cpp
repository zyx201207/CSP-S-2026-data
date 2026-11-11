#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else cout<<1;

    bool _=true;
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<0;
        _=0;
    }
    else cout<<1;

    bool _1=(s1[2]>='A'&&s1[2]<='C');
    bool _2=(s2[2]>='A'&&s2[2]<='C');
    bool _3=(s1[2]=='D');
    bool _4=(s2[2]=='D');
    bool _5=(s1[2]=='F');
    bool _6=(s2[2]=='F');
    bool _z=((_3&&_4)||(_3&&_6)||(_5&&_4)||(_5&&_6));

    if(_&&(_1&&_2)){
        cout<<1;
    }
    else if(_&&_z){
        cout<<1;
    }
    else {
        cout<<0;
    }

    int sr=s1[0]*10+s1[1]-528;
    int sx=s2[0]*10+s2[1]-528;
    bool _7=((s1[2]=='C')&&(s2[2]=='D'));
    bool _8=((s1[2]=='D')&&(s2[2]=='C'));
    if((abs(sr-sx)==1)&&(s1[2]==s2[2])){
        cout<<1;
    }
    else if((abs(s1[2]-s2[2])==1)&&(sr==sx)&&!_7&&!_8){
        cout<<1;
    }
    else cout<<0;

    return 0;
}
