#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        printf("1");
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            printf("1");
            int x1=(s1[2]-'A');
            int x2=(s2[2]-'A');
            if(x1<=2 && x2<=2 || x1>=3 && x2>=3){
                printf("1");
                if(s1[2]=='F'){
                    x1--;
                }
                if(s2[2]=='F'){
                    x2--;
                }
                if(abs(x1-x2)==1){
                    printf("1");
                }else{
                    printf("0");
                }
            }else{
                printf("00");
            }
        }else{
            printf("000");
        }
    }else{
        printf("0000");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
