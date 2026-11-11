
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"){
        cout<<1;
    }else{
    cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
    cout<<0;
    }
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1||s1[2]-s2[2]==2||s2[2]-s1[2]==2){
        cout<<1;
    }else{
    cout<<0;}
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
        cout<<1;
    }else{
    cout<<0;}


}
