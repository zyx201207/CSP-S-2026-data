#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rf,rl,ff,fl;
    bool flag1=0,flag2=0,flag3=0,linshi=0;
    vector<int> rfa,rla,ffa,fla;
    cin>>rf>>rl>>ff>>fl;


    for(int i=0;i<2;i++){
       if(isdigit(rf[i])){
            rfa.push_back(rf[i]-'0');
       }
       if(isdigit(ff[i])){
            ffa.push_back(ff[i]-'0');
       }
    }
    if(rfa[0]==ffa[0]&&rfa[1]==ffa[1]){
        flag1=1;
        cout<<1;
    }else{cout<<0;}


    for(int i=0;i<3;i++){
        if(isdigit(rl[i])){
            rla.push_back(rl[i]-'0');
       }
       if(isdigit(fl[i])){
            fla.push_back(fl[i]-'0');
       }
    }
    if(rla[0]==fla[0]&&rla[1]==fla[1]&&flag1==1){
        flag2=1;
        cout<<1;
    }else{cout<<0;}

    if((rl[2]<='C'&&fl[2]<='C')||(rl[2]>='D'&&fl[2]>='D')){
        linshi=1;
    }
    if(linshi==1&&flag1==1&&flag2==1){
        flag3=1;
        cout<<1;
    }else{cout<<0;}

    bool check=0;
    if((max(rl[2],fl[2])-min(rl[2],fl[2])==1)&&max(rl[2],fl[2])!='D'){
        if(flag1==1&&flag2==1&&flag3==1){
            check=1;
            cout<<1;
        }
    }
    if((max(rl[2],fl[2])-min(rl[2],fl[2])==2)&&max(rl[2],fl[2])=='F'){
        if(flag1==1&&flag2==1&&flag3==1){
            check=1;
            cout<<1;
        }
    }if(check==0){cout<<0;}

    fclose(stdin);
    fclose(stdout);
    return 0;
}
