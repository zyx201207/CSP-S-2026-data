#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1="",s1="",c2="",s2="";
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        printf("0000");
        return 0;
    }
    if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        printf("1000");
        return 0;
    }
    if(((s1[2]>='D' && s2[2]>='D') || (s1[2]<='D' && s2[2]<='D')) && (s1[2]!='C' || s2[2]!='D') && (s1[2]!='D' || s2[2]!='C')){
        printf("111");
        if(abs(s1[2]-s2[2])==1){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    else{
        printf("1100");
        return 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

