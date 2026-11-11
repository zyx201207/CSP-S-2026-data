#include<bits/stdc++.h>
using namespace std;
char s[5];
int main(){
//    freopen("travel.in","r",stdin);
//    freopen("travel.out","w",stdout);
    char c1[5],c2[5],s1[5],s2[5];
    scanf("%s%s%s%s",c1,s1,c2,s2);
    int rc=0,rs=0,xc=0,xs=0;
    rc=(c1[0]-'0')*10+(c1[1]-'0');
    xc=(c2[0]-'0')*10+(c2[1]-'0');
    if(rc==xc){
        s[1]='1';
    }else{
        s[1]='0';
    }
    for(int i=0;i<3;i++){
        if(s1[i]>='0'&&s1[i]-'0'<=9){
            rs=rs*10+(s1[i]-'0');
        }
    }
    for(int i=0;i<3;i++){
        if(s2[i]>='0'&&s2[i]-'0'<=9){
            xs=xs*10+(s2[i]-'0');
        }
    }
    if(rs==xs){
        s[2]='1';
    }else{
        s[2]='0';
    }
    if(s1[2]-'C'<=0&&s2[2]-'C'<=0||s1[2]-'C'>0&&s2[2]-'C'>0){
        s[3]='1';
    }else{
        s[3]='0';
    }
    if(abs(s1[2]-s2[2])==1){
        s[4]='1';
    }else{
        s[4]='0';
    }
    for(int i=1;i<=4;i++){
        cout<<s[i];
    }
    return 0;
}
