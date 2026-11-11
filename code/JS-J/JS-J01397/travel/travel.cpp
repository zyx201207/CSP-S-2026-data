#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        printf("1");
    }
    else{
        printf("0000\n");
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        printf("1");
    }
    else{
        printf("000\n");
        return 0;
    }
    if((s1[2]-'C'<=0&&s2[2]-'C'<=0)||(s1[2]-'C'>0&&s2[2]-'C'>0)){
        printf("1");
    }
    else{
        printf("00\n");
        return 0;
    }
    if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}