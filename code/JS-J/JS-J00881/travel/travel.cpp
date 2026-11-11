#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int che1,che2,pai1,pai2,wei1,wei2;
bool a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    che1=(s1[0]^48)*10+(s1[1]^48);
    che2=(s3[0]^48)*10+(s3[1]^48);
    pai1=(s2[0]^48)*10+(s2[1]^48);
    pai2=(s4[0]^48)*10+(s4[1]^48);
    wei1=s2[2]-'A'+1;
    wei2=s4[2]-'A'+1;
    a=0;b=0;c=0;d=0;
    if(che1==che2){
        a=1;
        if(pai1==pai2){
           b=1;
           if((wei1>3)&&(wei2>3))c=1,d=1;
           else if((wei1<4)&&(wei2<4)){
                    c=1;
                    if(abs(wei1-wei2)==1)d=1;
           }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
