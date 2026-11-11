#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string a1,a2;
    char b1,b2;
    a1=s1[0]+s1[1];
    a2=s2[0]+s2[1];
    b1=s1[2];
    b2=s2[2];
    if(c1!=c2){
        cout<<"0000";
    }
    else{
        if(a1!=a2){
            cout<<"1000";
        }
        else{
            if(abs(int(b1-b2))>2||b1=='C'&&b2=='D'||(b1=='D'&&b2=='C')){
                cout<<"1100";
            }
            else{
                if(b1==b2+1||b1==b2-1||(b1=='D'&&b2=='F')||(b1=='F'&&b2=='D')) cout<<"1111";
                else cout<<"1110";
            }
        }
    }
}
