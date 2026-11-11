#include<bits/stdc++.h>
using namespace std;
bool o[15];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,ap,b,bp;
    cin>>a>>ap>>b>>bp;
    o[3]=1;
    if(a==b){
        o[1]=1;
        if((ap[0]==bp[0])&&(ap[1]==bp[1])){
            o[2]=1;

            if(ap[2]==(bp[2]+1)||ap[2]==(bp[2]-1)){
                o[4]=1;
            }
            if(((ap[2]=='C')&&(bp[2]=='D'))||((ap[2]=='D')&&(bp[2]=='C'))){
                o[3]=0;
                o[4]=0;
            }
        }else{
            o[3]=0;
            o[4]=0;
        }
    }else{
        o[2]=0;
        o[3]=0;
        o[4]=0;
    }
    cout<<o[1]<<o[2]<<o[3]<<o[4];
}
