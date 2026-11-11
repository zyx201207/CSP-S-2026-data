#include<bits/stdc++.h>
using namespace std;
string s1,s2,q1,q2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>q1>>s2>>q2;
    if(s1==s2){
        cout<<'1';
        if(q1[0]==q2[0]&&q1[1]==q2[1]){
            cout<<'1';
            if(q1[2]=='A'&&(q2[2]=='C'||q2[2]=='B')){
                cout<<'1';
            }else if(q1[2]=='B'&&(q2[2]=='C'||q2[2]=='A')){
                cout<<'1';
            }else if(q1[2]=='C'&&(q2[2]=='B'||q2[2]=='A')){
                cout<<'1';
            }else if(q1[2]=='D'&&q2[2]=='F'){
                cout<<'1';
            }else if(q1[2]=='F'&&q2[2]=='D'){
                cout<<'1';
            }else{
                cout<<'0';
            }
            if(q1[2]=='A'&&q2[2]=='B'){
                cout<<'1';
            }else if(q1[2]=='B'&&(q2[2]=='C'||q2[2]=='A')){
                cout<<'1';
            }else if(q1[2]=='C'&&q2[2]=='B'){
                cout<<'1';
            }else if(q1[2]=='D'&&q2[2]=='F'){
                cout<<'1';
            }else if(q1[2]=='F'&&q2[2]=='D'){
                cout<<'1';
            }else{
                cout<<'0';
            }
        }else{
            cout<<"000";
        }

    }else{
        cout<<"0000";
    }
    return 0;
}

