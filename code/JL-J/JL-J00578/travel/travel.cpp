#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool f1=1,f2=1,f3=1,f4=1;
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1[0]!=c3[0]||c1[1]!=c3[1]){
        f1=0,f2=0,f3=0,f4=0;
    }else if(c2[0]!=c4[0]||c2[1]!=c4[1]){
        f2=0,f3=0,f4=0;
    }else if(!((c2[2]-'0'<=19&&c4[2]-'0'<=19)||(c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D'))){
        f3=0,f4=0;
    }else if(!(abs((c2[2]-'0')-(c4[2]-'0'))==1||(c2[2]=='F'&&c4[2]=='D')||(c2[2]=='D'&&c4[2]=='F'))){
        f4=0;
    }
    //int a=abs((c2[2]-'0')-(c4[2]-'0'));
    //cout<<a;
    if(f1)cout<<1;else cout<<0;
    if(f2)cout<<1;else cout<<0;
    if(f3)cout<<1;else cout<<0;
    if(f4)cout<<1;else cout<<0;
    return 0;
}
