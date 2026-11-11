#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4,r1="0",r2="0",r3="0",r4="0";
    cin>>c1>>c2>>c3>>c4;
    bool s1,s2;
    s1=(c2[2]<='C'&&c2[2]>='A'&&c4[2]<='C'&&c4[2]>='A');
    s2=(c2[2]<='F'&&c2[2]>='D'&&c4[2]<='F'&&c4[2]>='D');
    if(c1==c3){
        r1="1";
        if(c2[0]+c2[1]==c4[0]+c4[1]){
            r2="1";
            if(s1||s2){
                r3="1";
                if((s1&&(c2[2]==c4[2]+1||c2[2]==c4[2]-1))||s2){
                    r4="1";
                }
            }
        }
    }
    cout<<r1+r2+r3+r4;
    return 0;
}
