#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int p1=s1[0]-'0',p2=s1[1]-'0',p3=s1[2]-'A';
    int p4=s2[0]-'0',p5=s2[1]-'0',p6=s2[2]-'A';
    if(c1==c2){
        a=1;
        if(p1==p4&&p2==p5){
            b=1;
            if((p3<=2&&p6<=2)||(p3>=3&&p6>=3)){
                c=1;
                if(p3-p6>=-1&&p3-p6<=1) d=1;
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
