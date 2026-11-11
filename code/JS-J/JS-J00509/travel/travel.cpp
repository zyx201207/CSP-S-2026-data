#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool a1,a2,a3,a4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1[0]-48==c3[0]-48&&c1[1]-48==c3[1]-48) cout<<"1",a1=true;
    else cout<<"0";
    if(c2[0]-48==c4[0]-48&&c2[1]-48==c4[1]-48&&a1==true) cout<<"1",a2=true;
    else cout<<"0";
        if((c4[2]=='A'||c4[2]=='B'||c4[2]=='C')&&a1==true&&a2==true)
           if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
            cout<<"1",a3=true;
           }
     if((c2[2]=='D'||c2[2]=='F')&&a1==true&&a2==true){
        if(c4[2]=='D'||c4[2]=='F')
            if(a2==true) cout<<"1",a3=true;
    }
    if(a3==false) cout<<"0";
    int x=c2[2]-1;
    int y=c4[2]-1;
    if(abs(x-y)==1&&a1==true&&a3==true&&a2==true) cout<<"1";
    else cout<<"0";
    return 0;
}
