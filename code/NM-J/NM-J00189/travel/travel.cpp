#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;

    }
    string s1=b.substr(0,2);
    string s2=d.substr(0,2);
    if(s1==s2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;

    }
    s1=b.substr(2,1);
    s2=d.substr(2,1);
    if(s1=="A"&&s2=="B"||s1=="B"&&s2=="A"||s1=="A"&&s2=="C"||s1=="C"&&s2=="A"||s1=="C"&&s2=="B"||s1=="B"&&s2=="C"||s1=="D"&&s2=="F"||s1=="F"&&s2=="D"){
        cout<<"1";
    }
    else{
        cout<<"0";

    }
    if(s1=="A"&&s2=="B"||s1=="B"&&s2=="A"||s1=="C"&&s2=="B"||s1=="B"&&s2=="C"||s1=="D"&&s2=="F"||s1=="F"&&s2=="D"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
