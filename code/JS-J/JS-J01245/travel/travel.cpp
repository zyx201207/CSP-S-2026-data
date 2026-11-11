#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","read",stdin);
    freopen("travel.out","write",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    char a1=s1[2],a2=s2[2];
    string s="";
    s+=a1;
    s+=a2;
    s1.pop_back();
    s2.pop_back();
    if(s1==s2){
        cout<<"1";
        if(s=="AB"||s=="BA"||s=="AC"||s=="CA"||s=="BC"||s=="CB"||s=="EF"||s=="FE"){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        if(s=="AB"||s=="BA"||s=="BC"||s=="CB"||s=="EF"||s=="FE"){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"000";
    }
    return 0;
}
