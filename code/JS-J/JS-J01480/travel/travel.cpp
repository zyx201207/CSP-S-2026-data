#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    int pai1=(s1[0]-'0')*10+(s1[1]-'0');
    int pai2=(s2[0]-'0')*10+(s2[1]-'0');
    if(pai1!=pai2){
        cout<<1000;
        return 0;
    }
    int pos1,pos2;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        pos1=1;
    }
    else{
        pos1=2;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
        pos2=1;
    }
    else{
        pos2=2;
    }
    if(pos1!=pos2){
        cout<<1100;
        return 0;
    }
    if(pos1==2){
        cout<<1111;
        return 0;
    }
    if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
        cout<<1111;
        return 0;
    }
    cout<<1110;
    return 0;
}
