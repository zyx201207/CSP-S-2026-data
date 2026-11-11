#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    int rc,rs1,xc,xs1,issame=0;
    char rs2,xs2;
    cin>>rc>>rs1>>rs2>>xc>>xs1>>xs2;
    if(rc==xc){
        issame++;
        if(rs1==xs1){
            issame++;
            if(rs2-'A'<3&&xs2-'A'<3){
                issame++;
                if(((rs2-'A')-(xs2-'A')==1)||((rs2-'A')-(xs2-'A')==-1))issame++;
            }
            if(rs2-'A'>=3&&xs2-'A'>=3)issame+=2;
        }
    }
    for(int i=0;i<issame;i++)cout<<'1';
    for(int i=0;i<(4-issame);i++)cout<<'0';
    return 0;
}
