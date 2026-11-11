#include<bits/stdc++.h>
using namespace std;
string ci,cj,si,sj,pos="ABCDF";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ci>>si>>cj>>sj;
    if(ci[0]!=cj[0]||ci[1]!=cj[1]){cout<<"0000\n"; return 0;} 
    if(si[0]!=sj[0]||si[1]!=sj[1]){cout<<"1000\n"; return 0;}
    if(si[2]=='A'||si[2]=='B'||si[2]=='C')
        if(!(sj[2]=='A'||sj[2]=='B'||sj[2]=='C')){cout<<"1100\n"; return 0;}
    if(si[2]=='D'||si[2]=='F')
        if(!(sj[2]=='D'||sj[2]=='F')){cout<<"1100\n"; return 0;}
    if(si[2]=='A'&&sj[2]=='B') cout<<"1111\n";
    else if(si[2]=='B'&&(sj[2]=='A'||sj[2]=='C')) cout<<"1111\n";
    else if(si[2]=='C'&&sj[2]=='B') cout<<"1111\n";
    else if(si[2]=='D'&&sj[2]=='F') cout<<"1111\n";
    else if(si[2]=='F'&&sj[2]=='D') cout<<"1111\n";
    else cout<<"1110\n";
    return 0;

}