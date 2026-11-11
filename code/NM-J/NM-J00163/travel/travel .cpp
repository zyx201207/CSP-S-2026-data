#include<bits/stdc++.h>
using namespace std;
int a1,a2,c1,c2;
char b1[10],b2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1;
    for(int i=1;i<=3;i++){
        cin>>b1[i];
    }
    cin>>a2;
    for(int i=1;i<=3;i++){
        cin>>b2[i];
    }
    if(a1!=a2){
        cout<<0<<0<<0<<0;
        return 0;
    }
    c1=(b1[1]-48)*10+b1[2]-48;
    c2=(b2[1]-48)*10+b2[2]-48;
    if(c1!=c2){
        cout<<1000;
        return 0;
    }
    if(b1[3]=='A'&&(b2[3]=='D'||b2[3]=='F')||b1[3]=='B'&&(b2[3]=='D'||b2[3]=='F')||b1[3]=='C'&&(b2[3]=='D'||b2[3]=='F')||b1[3]=='D'&&(b2[3]=='A'||b2[3]=='B'||b2[3]=='C')||b1[3]=='F'&&(b2[3]=='A'||b2[3]=='B'||b2[3]=='C')){
        cout<<1100;
        return 0;
    }
    if(b1[3]=='A'&&b2[3]=='C'||b1[3]=='C'&&b2[3]=='A'){
        cout<<1110;
        return 0;
    }
    cout<<1111;
	return 0;
}
