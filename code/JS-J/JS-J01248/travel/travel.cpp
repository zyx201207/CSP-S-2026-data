#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,q1,q2;
char h1,h2;
bool check(){
    if(h1=='A'&&h2=='D')return false;
    if(h1=='B'&&h2=='D')return false;
    if(h1=='C'&&h2=='D')return false;
    if(h1=='A'&&h2=='F')return false;
    if(h1=='B'&&h2=='F')return false;
    if(h1=='C'&&h2=='F')return false;
    if(h2=='A'&&h1=='D')return false;
    if(h2=='B'&&h1=='D')return false;
    if(h2=='C'&&h1=='D')return false;
    if(h2=='A'&&h1=='F')return false;
    if(h2=='B'&&h1=='F')return false;
    if(h2=='C'&&h1=='F')return false;
    return true;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    q1=s1[0]+s1[1],q2=s2[0]+s2[1];
    h1=s1[2],h2=+s2[2];
    if(c1==c2){
        cout<<1;
        if(q1==q2){
            cout<<1;
            if(check()){
                cout<<1;
                if(h1-h2==1||h2-h1==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
