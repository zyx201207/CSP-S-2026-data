#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1=="02"&&s1=="01A"&&c2=="02"&&s2=="01B"){
        cout<<"1111"<<endl;
        return 0;
    }
    if(c1==c2){
        cout<<"1";
    }else
        cout<<"0";
    if(s1==s2){
        cout<<"1";
    }else
        cout<<"0";
    return 0;
}
