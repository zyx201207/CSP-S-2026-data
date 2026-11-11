#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel3.in","r",stdin);
    freopen("travel3.out","w",stdout);
    string cx1,zw1,cx2,zw2,sum="";
    cin>>cx1>>zw1>>cx2>>zw2;
    if(cx1==cx2) sum+='1';
    else sum+='0';
    if(cx1==cx2){
        if(zw1[0]==zw2[0] && zw1[1]==zw2[1]) sum+='1';
        else sum+='0';
    }
    else sum+='0';
    if(cx1==cx2){
        if(zw1[0]==zw2[0] && zw1[1]==zw2[1]){
            if(zw1[2]=='A'&&zw2[2]=='B' || zw1[2]=='A'&&zw2[2]=='C' || zw1[2]=='B'&&zw2[2]=='A' || zw1[2]=='B'&&zw2[2]=='C' || zw1[2]=='C'&&zw2[2]=='A' || zw1[2]=='C'&&zw2[2]=='B' || zw1[2]=='D'&&zw2[2]=='F' || zw1[2]=='F'&&zw2[2]=='D') sum+='1';
            else sum+='0';
        }
        else sum+='0';
    }
    else sum+='0';
    if(cx1==cx2){
        if(zw1[0]==zw2[0] && zw1[1]==zw2[1]){
            if(zw1[2]=='A'&&zw2[2]=='B' || zw1[2]=='A'&&zw2[2]=='C' || zw1[2]=='B'&&zw2[2]=='A' || zw1[2]=='B'&&zw2[2]=='C' || zw1[2]=='C'&&zw2[2]=='A' || zw1[2]=='C'&&zw2[2]=='B' || zw1[2]=='D'&&zw2[2]=='F' || zw1[2]=='F'&&zw2[2]=='D'){
                if(zw1[2]=='A'&&zw2[2]=='B' || zw1[2]=='B'&&zw2[2]=='A' || zw1[2]=='B'&&zw2[2]=='C' || zw1[2]=='C'&&zw2[2]=='B' || zw1[2]=='D'&&zw2[2]=='F' || zw1[2]=='F'&&zw2[2]=='D') sum+='1';
                else sum+='0';
            }
            else sum+='0';
        }
        else sum+='0';
    }
    else sum+='0';
    cout<<sum;
    return 0;
}
