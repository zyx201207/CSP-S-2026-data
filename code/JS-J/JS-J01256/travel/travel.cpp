#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string q,e;
    char w1,w2,w3,r1,r2,r3;
    cin>>q>>w1>>w2>>w3>>e>>r1>>r2>>r3;
    if(q!=e){
        cout<<"0000";
        return 0;
    }//1
    cout<<'1';
    if(w1==r1&&w2==r2){
        cout<<"1";
    }//2
    else {
        cout<<"000";
        return 0;
    }//2
    if((w3=='D'&&r3=='F')||(w3=='F'&&r3=='D')){
        cout<<"11";
        return 0;
    }//3 4
    else if((w3=='A'&&r3=='B')||(w3=='B'&&r3=='A')||(w3=='A'&&r3=='C')||(w3=='C'&&r3=='A')||(w3=='B'&&r3=='C')||(w3=='C'&&r3=='B')){
        //3
        cout<<'1';
        if((w3=='A'&&r3=='B')||(w3=='B'&&r3=='A')||(w3=='B'&&r3=='C')||(w3=='C'&&r3=='B')){
            cout<<'1';//4
        }
        else cout<<'0';//4
    }
    else cout<<"00";//3 4
    return 0;
}