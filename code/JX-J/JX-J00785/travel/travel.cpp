#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<"1";
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    char c=s1[2],b=s2[2];
    a1=s1[2]-'A';
    a2=s2[2]-'A';
    if(c<='C' && b<='C' || c>'C' && b>'C'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(a1+1==a2 || a1-1==a2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
