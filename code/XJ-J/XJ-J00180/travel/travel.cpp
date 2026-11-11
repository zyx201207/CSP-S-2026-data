#include<bits/stdc++.h>
using namespace std£»
typedef long long ll;
char  c1[15],s1[15],c2[15],s2=[15];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf(c1+1,s1+1,c2+1,s2+1);
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
        printf("1");
        if(s1[1]==s2[1]&&s2[2]==s2[2]){
            printf("1");

        }else{
        printf("000");
        return 0;
        }
    }
}

