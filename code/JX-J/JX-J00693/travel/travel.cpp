#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int a=0,b=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a2[2]=='D'||a2[2]=='F'){
        a=1;
    }
    if(b2[2]=='D'||b2[2]=='F'){
        b=1;
    }
    if(a1==b1) cout<<"1";
    else cout<<"0";
    if(a2[0]==b2[0]&&a2[1]==b2[1]&&a1==b1) cout<<"1";
    else cout<<"0";
    if(a==b&&a2[0]==b2[0]&&a2[1]==b2[1]&&a1==b1) cout<<"1";
    else cout<<"0";
    if(a==b&&a2[0]==b2[0]&&a2[1]==b2[1]&&a1==b1){
       if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1){
        cout<<"1";
       }
       else cout<<"0";}
    else cout<<"0";
    return 0;
}
