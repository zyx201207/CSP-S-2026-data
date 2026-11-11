#include<bits/stdc++.h>
using namespace std;
int a[3];
int b[3];
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    int xa;
    int ra;
    string xb,rb;
    cin>>xa;
    cin>>xb;
    cin>>ra;
    cin>>rb;
    if(xa==ra){
        cout<<"1";
    }else{
        cout<<"0"<<"0"<<"0"<<"0";
        return 0;
    }
    for(int i=0;i<=1;i++){
        a[i]=xb[i];
    }
    char aa=xb[2];
    for(int i=0;i<=1;i++){
        b[i]=rb[i];
    }
    char bb=rb[2];
    int flag=0;
    for(int i=0;i<=1;i++){
        if(a[i]==b[i]){
            flag+=1;
        }
    }
    if(flag==2){
        cout<<1;
    }else{
        cout<<"0"<<"0"<<"0";
        return 0;
    }
    int xx;
    if(aa=='A'){
        xx=1;
    }else if(aa=='B'){
        xx=2;
    }else if(aa=='C'){
        xx=3;
    }else if(aa=='D'){
        xx=4;
    }else if(aa=='F'){
        xx=5;
    }
    int rr;
    if(bb=='A'){
        rr=1;
    }else if(bb=='B'){
        rr=2;
    }else if(bb=='C'){
        rr=3;
    }else if(bb=='D'){
        rr=4;
    }else if(bb=='F'){
        rr=5;
    }
    if(xx==1||xx==2||xx==3&&rr==1||rr==2||rr==3){
        cout<<"1";
    }else if(xx==4||xx==5&&rr==4||rr==5){
        cout<<"1";
    }else{
        cout<<"0"<<"0";
        return 0;
    }
    if(xx-rr==1||rr-xx==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}

