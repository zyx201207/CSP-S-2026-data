#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s11,s12,s21,s22;
    cin>>s11>>s12>>s21>>s22;
    if(s11!=s21){
        printf("0000\n");
        return 0;
    }
    if(s12[0]!=s22[0]||s12[1]!=s22[1]){
        printf("1000\n");
        return 0;
    }
    int zhi1=0;
    int zhi2=0;
    if(s12[2]=='A'||s12[2]=='B'||s12[2]=='C'){
        zhi1=0;
    }else{
        zhi1=1;
    }
    if(s22[2]=='A'||s22[2]=='B'||s22[2]=='C'){
        zhi2=0;
    }else{
        zhi2=1;
    }
    if(zhi1!=zhi2){
        printf("1100\n");
        return 0;
    }
    if(zhi1==0){
        if(s12[2]=='A'&&s22[2]=='C'){
            printf("1110\n");
            return 0;
        }
        if(s12[2]=='C'&&s22[2]=='A'){
            printf("1110\n");
            return 0;
        }
    }
    printf("1111\n");
    return 0;
}

