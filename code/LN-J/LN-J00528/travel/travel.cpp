#include<bits/stdc++.h>
using namespace std;
int Rcarclass,Xcarclass,Q1=0,Q2=0,Q3=0,Q4=0,Rlienum,Xlienum;
char Rlie[3],Xlie[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>Rcarclass>>Rlie>>Xcarclass>>Xlie;
    if(Rcarclass==Xcarclass){
        Q1=1;
    }
    if(Rlie[0]==Xlie[0] && Rlie[1]==Xlie[1] && Q1){
        Q2=1;
    }
    if(Rlie[2]=='A' || Rlie[2]=='B' || Rlie[2]=='C'){
        Rlienum=1;
    }else{
        Rlienum=2;
    }
    if(Xlie[2]=='A' || Xlie[2]=='B' || Xlie[2]=='C'){
        Xlienum=1;
    }else{
        Xlienum=2;
    }
    if(Xlienum==Rlienum && Q2 && Q1){
        Q3=1;
    }
    if(Xlienum==2 && Q3 && Q2 && Q1){
        Q4=1;
    }else if((Xlie[2]+1==Rlie[2] || Xlie[2]-1==Rlie[2]) && Q3 && Q2 && Q1){
        Q4=1;
    }
    cout<<Q1<<Q2<<Q3<<Q4;
}
