#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2,s1,s2;
ll num1,num2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    num1=s1[2]-'A';
    num2=s2[2]-'A';
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(num1<=2&&num2<=2){
        cout<<"1";
        if(num1<num2){
            swap(num1,num2);
        }
        if(num1==num2+1){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    else if(num1>2&&num2>2){
        cout<<"11";
        return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    return 0;
}
