#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool fp=true;
    string rc,rz,xc,xz;
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc){
        printf("1");
        for(int i=0;i<2;i++){
            if(rz[i]!=xz[i]){
                fp=false;
                break;
            }
        }
        if(fp==true){
            printf("1");
            char a=rz[2],b=xz[2];
            if(((a>='A') && (a<='C') && (b>='A') && (b<='C')) || ((a>='D') && (a<='E') && (b>='D') && (b<='E'))){
                printf("1");
                if(abs(a-b)==1) printf("1");
                else printf("0");
            }else printf("00");
        }else printf("000");
    }else printf("0000");
    return 0;
}
