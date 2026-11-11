#include <bits/stdc++.h>
using namespace std;
char c1[10],c2[10],s1[10],s2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        printf("0000");
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        printf("1000");
        return 0;
    }
    if((s1[3]>='D'&&s2[3]<='C')||s2[3]>='D'&&s1[3]<='C'){
        printf("1100");
        return 0;
    }
    if(((s1[3]=='A')&&(s2[3]=='C'))||(s2[3]=='A'&&s1[3]=='C')){
        printf("1110");
        return 0;
    }
    printf("1111");
    return 0;
}
