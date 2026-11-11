#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a1>>a2>>b1>>b2;
if(a1!=b1){
    cout<<"0000";
}
else{
    cout<<1;
    string s1=a2.substr(0,2);
    string s2=b2.substr(0,2);
    if(s1==s2){
        cout<<1;
        char d1=a2[2],d2=b2[2];
        if(d1!='D'&&d1!='F'&&d2!='D'&&d2!='F'||d1=='D'&&d2=='F'||d1=='F'&&d2=='D'){
            cout<<1;
            if(abs(d1-'A'-(d2-'A'))==1){
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
return 0;
}
