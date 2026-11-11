#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
                if(abs((int)s1[2]-s2[2])==1){
                    printf("1111");
                }
                else printf("1110");
            }
            else printf("1100");
        }
        else printf("1000");
    }
    else printf("0000");
    return 0;
}