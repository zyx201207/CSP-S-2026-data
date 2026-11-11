#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    int n1,n2;
    char t1,t2;
    cin>>c1>>s1>>c2>>s2;
    n1=(s1[0]-'0')*10+(s1[1]-'0');
    n2=(s2[0]-'0')*10+(s2[1]-'0');
    t1=s1[2];
    t2=s2[2];
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(n1==n2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((t1=='A'&&t2=='B')||(t1=='A'&&t2=='C')||(t1=='B'&&t2=='C')||(t1=='D'&&t2=='F')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')||(t1=='D'&&t2=='F')){
        cout<<1;
    }else{
        cout<<"0";
        return 0;
    }
    return 0;
}
