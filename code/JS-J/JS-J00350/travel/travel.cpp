#include<bits/stdc++.h>
using namespace std;
string atn,acn,btn,bcn;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>atn>>acn>>btn>>bcn;
    if((atn[0]+atn[1])-'0'!=(btn[0]+btn[1])-'0'){
        cout<<"0000";
        return 0;
    }
    int acc=(acn[0]+acn[1])-'0',bcc=(bcn[0]+bcn[1])-'0';
    if(acc!=bcc){
        cout<<"1000";
        return 0;
    }
    int bb=bcn[2]-'A',aa=acn[2]-'A';
    if(bb>=3&&aa<=2||aa>=3&&bb<=2){
        cout<<"1100";
        return 0;
    }
    if((abs(bb-aa)==1||aa==5&&bb==3||aa==3&&bb==5)&&(bb!=2&&aa!=3||bb!=3&&aa!=2)){
        cout<<"1111";
        return 0;
    }
    else{
        cout<<"1110";
        return 0;
    }
    return 0;
}
