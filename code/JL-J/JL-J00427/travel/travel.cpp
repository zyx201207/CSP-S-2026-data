#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int firstcar,secondcar;
    string firstset,secondset;
    cin>>firstcar>>firstset>>secondcar>>secondset;
    if(firstcar!=secondcar){
        cout<<"0000";
        return 0;
    }
    int firstnumber=firstset[0]*10+firstset[1],secondnumber=secondset[0]*10+secondset[1];
    if(firstnumber!=secondnumber){
        cout<<"1000";
        return 0;
    }
    char firstchar=firstset[2],secondchar=secondset[2];
    if(firstchar>='A'&&firstchar<='C'&&secondchar>='D'&&secondchar<='F'){
        cout<<"1100";
        return 0;
    }
    if(firstchar>='D'&&firstchar<='F'&&secondchar>='A'&&secondchar<='C'){
        cout<<"1100";
        return 0;
    }
    //char firstchar=firstset[2],secondchar=secondset[2];
    if(firstchar=='A'&&secondchar=='C'){
        cout<<"1110";
        return 0;
    }
    if(firstchar=='C'&&secondchar=='A'){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
