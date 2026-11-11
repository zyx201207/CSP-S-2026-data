#include<bits/stdc++.h>
using namespace std;
void p(char k1,char k2)
{
    if(k1=='D'||k1=='F'){
        if(k2=='A'||k2=='B'||k2=='C')cout<<"00";
        else cout<<"11";
    }
    else {
        if(k2=='A'||k2=='B'||k2=='C'){
            if(k1=='A'&&k2=='C')cout<<10;
            else if(k2=='C'&&k1=='A')cout<<10;
            else cout<<11;
        }
        else cout<<"00";
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string t1,t2;
    t1+=s1[0];
    t1+=s1[1];
    t2+=s2[0];
    t2+=s2[1];
    char k1,k2;
    k1=s1[2];
    k2=s2[2];
    if(c1==c2){
        cout<<1;
        if(t1==t2){
            cout<<1;
            p(k1,k2);
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
