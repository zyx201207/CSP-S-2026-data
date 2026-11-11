#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,sr,cx,sx;
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        printf("1");
    }
    else{
        printf("0000");
        return 0;
    }
    string p="",p2="";
    int len=sr.size();
    for(int i=0;i<len-1;++i){
        p+=sr[i];
        p2+=sx[i];
    }
    if(p==p2){
        printf("1");
    }
    else{
        printf("000");
        return 0;
    }
    int nn=len-1;
    char h=sr[nn],hh=sx[nn];
    if(h>='A'&&h<='C'){
        if(hh=='D'||hh=='F'){
            printf("00");
        }
        else{
            printf("1");
            if(abs(hh-h)==1){
                printf("1");
            }
            else{
                printf("0");
            }
        }
    }
    else{
        if(hh>='A'&&hh<='C'){
            printf("00");
        }
        else{
            printf("1");
            if(abs(hh-h)==1){
                printf("1");
            }
            else{
                printf("0");
            }
        }
    }
    return 0;
}
