#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!="01"&&c1!="16"){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    string a=s1.substr(0,2);
    string b=s2.substr(0,2);
    if(a==b){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    char a1=s1[2];
    char a2=s2[2];
    if(((a1=='A'||a1=='B'||a1=='C')&&(a2=='A'||a2=='B'||a2=='C'))||((a1=='D'||a1=='E')&&(a2=='D'||a2=='E'))){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if((a1=='D'&&a1=='E')||(a1=='E'&&a2=='D')||(a1=='A'&&a2=='B')||(a1=='B'&&a2=='A')||(a1=='B'&&a2=='C')||(a1=='C'&&a2=='B')){
        cout<<"1";
    }else{
        cout<<"0";
    }

    return 0;
}