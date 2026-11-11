#include<bits/std c++.h>
using namespace std;
int main{
    freopen("travel.in","w",stdin)
    freopen("travel.out","r",stdout)
    string c1,c2,c3,c4;
    bool z1=1,z2=1,z3=1,z4=1;
    cin>>c1>>c2>>c3>>c4;
    if(c1[0]!=c3[0]||c1[1]!c3[1]){
       z1=0,z2=0,z3=0,z4=0;
    }else if(c2[0]!=c4[0]||c2[1]!c4[1]){
       z2=0,z3=0,z4=0;
    }else if(!((c2[2]-'0'<=19&&c4[2]-'0'<=19)||(c2[2]=='F')||(c2[2]='F'&&c4[2]=='D'))){
       z3=0,z4=0;
    }else if(!(abs((c2[2]-'0')-(c4[2]-'0'))==1||(c2[2]=='F'&&c4[2]='D')||(c2[2]=='D'&&c4[2]=='F'))){
       z4=0;
    }
    if(z1)cout<<1;else cout<<0;
    if(z2)cout<<1;else cout<<0;
    if(z3)cout<<1;else cout<<0;
    if(z4)cout<<1;else cout<<0;
    return 0;
}
