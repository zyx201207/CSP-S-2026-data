#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int flag=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]){
            flag++;
        }
    }
    if(flag==2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    flag=0;
    if(s1[2]=='A'&&s2[2]=='B'){
        cout<<"11";
        flag=1;
    }
    if(s1[2]=='B'&&s2[2]=='A'){
        cout<<"11";
        flag=1;
    }
    if(s1[2]=='A'&&s2[2]=='C'){
        cout<<"10";
        flag=1;
    }
    if(s1[2]=='C'&&s2[2]=='A'){
        cout<<"10";
        flag=1;
    }
    if(s1[2]=='B'&&s2[2]=='C'){
        cout<<"11";
        flag=1;
    }
    if(s1[2]=='C'&&s2[2]=='B'){
        cout<<"11";
        flag=1;
    }
    if(s1[2]=='D'&&s2[2]=='F'){
        cout<<"11";
        flag=1;
    }
    if(s1[2]=='F'&&s2[2]=='D'){
        cout<<"11";
        flag=1;
    }
    if(flag==0){
        cout<<"00";
    }
    return 0;
}
