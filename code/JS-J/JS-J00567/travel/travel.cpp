#include<bits/stdc++.h>
using namespace std;

char c1[50],s1[50],c2[50],s2[50];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
    bool ok=0;
    for(int i=1;i<=2;i++){
        if(c1[i]!=c2[i]){
            ok=1;
        }
    }
    if(ok){
        cout<<"0000";
        return 0;
    }else{
        cout<<'1';
    }
    for(int i=1;i<=2;i++){
        if(s1[i]!=s2[i]){
            ok=1;
        }
    }
    if(ok){
        cout<<"000";
        return 0;
    }else{
        cout<<'1';
    }
    if(s1[3]>s2[3]){
        if(s1[3]>='D'&&s2[3]<='C'){
            ok=1;
        }
    }else if(s1[3]<s2[3]){
        if(s1[3]<='C'&&s2[3]>='D'){
            ok=1;
        }
    }
    if(ok){
        cout<<"00";
        return 0;
    }else{
        cout<<'1';
    }
    if(s1[3]==s2[3]+1||s1[3]==s2[3]-1){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}
