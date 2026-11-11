#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
         cout<<"0000";
         return 0;
    }
    char z1=s1[2],ok=0;
    char z2=s2[2];
    int s11=(s1[0]-'0')*10+s1[1]-'0';
    int s22=(s2[0]-'0')*10+s2[1]-'0';
    if(s11==s22){
        cout<<1;
        if(((z1=='A'||z1=='B'||z1=='C')&&(z2=='D'||z2=='F'))||((z2=='A'||z2=='B'||z2=='C')&&(z1=='D'||z1=='F'))){
            cout<<"00";
            return 0;
        }
        else cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(ok==0&&abs(z1-z2)==1){
        cout<<1;
    }
    else cout<<0;
    //02 02B 02 01A
    return 0;
}
