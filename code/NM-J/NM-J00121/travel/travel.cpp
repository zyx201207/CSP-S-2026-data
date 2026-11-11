#include<bits/stdc++.h>
using namespace std;
bool tongce(char a,char b){
    if(a=='A'&&b=='B')return 1;
    if(a=='B'&&b=='A')return 1;
    if(a=='C'&&b=='A')return 1;
    if(a=='A'&&b=='C')return 1;
    if(a=='B'&&b=='C')return 1;
    if(a=='C'&&b=='B')return 1;
    if(a=='D'&&b=='F')return 1;
    if(a=='F'&&b=='D')return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char cr[2],sr[3],cx[2],sx[3];
    for(int i = 0;i<2;i++){
        cin>>cr[i];
    }
    for(int i = 0;i<3;i++){
        cin>>sr[i];
    }
    for(int i = 0;i<2;i++){
        cin>>cx[i];
    }
    for(int i = 0;i<3;i++){
        cin>>sx[i];
    }
    if(cr[0]==cx[0]&&cr[1]==cx[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(cr[0]==cx[0]&&cr[1]==cx[1]  &&  sr[0]==sx[0]&&sr[1]==sx[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(cr[0]==cx[0]&&cr[1]==cx[1]  &&  sr[0]==sx[0]&&sr[1]==sx[1]  &&  tongce(sr[2],sx[2])){
        cout<<1;
    }else{
        cout<<0;
    }
    if(cr[0]==cx[0]&&cr[1]==cx[1]  &&  sr[0]==sx[0]&&sr[1]==sx[1]  &&  tongce(sr[2],sx[2])  &&  (sr[2]+1==sx[2]||sr[2]-1==sx[2])){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
