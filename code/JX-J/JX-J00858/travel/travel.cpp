#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2){
        cout<<1;
        vis=1;
    }else{
        cout<<0;
        vis=0;
    }
    if(vis&&b1[0]==b2[0]&&b1[1]==b2[1]){
        cout<<1;
    }else{
        cout<<0;
        vis=0;
    }
    if(vis&&(b1[2]<='C'&&b2[2]<='C')||(b1[2]>'C'&&b2[2]>'C')){
        cout<<1;
    }else{
        cout<<0;
        vis=0;
    }
    if(vis&&abs(b1[2]-b2[2])==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
