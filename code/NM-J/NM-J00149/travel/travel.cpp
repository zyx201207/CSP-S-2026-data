#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[20],c2[20],s1[20],s2[20];
    scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
    bool a=false,b=false,c=false,d=false;
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
        a=true;
        if(s1[1]==s2[1]&&s1[2]==s2[2]){
            b=true;
            if((s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D')){
                d=true;
                c=true;
            }else if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')){
                d=true;
                c=true;
            }else if((s1[3]=='B'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='B')){
                d=true;
                c=true;
            }else if((s1[3]=='A'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='A')){
                c=true;
            }
        }
    }
    char ans[20]={};
    if(a){
        ans[1]='1';
    }else{
        ans[1]='0';
    }
    if(b){
        ans[2]='1';
    }else{
        ans[2]='0';
    }
    if(c){
        ans[3]='1';
    }else{
        ans[3]='0';
    }
    if(d){
        ans[4]='1';
    }else{
        ans[4]='0';
    }
    for(int i=1;i<=4;i++){
        printf("%c",ans[i]);
    }
    return 0;
}
