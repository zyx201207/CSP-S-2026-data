#include<bits/stdc++.h>
using namespace std;
int x1,x2,l1,l2;
char w1,w2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d%c%d%d%c",&x1,&l1,&w1,&x2,&l2,&w2);
    if(x1==x2){
        printf("1");
        if(l1==l2){
            printf("1");
            if(!(w1<='C'^w2<='C')){
                printf("1");
                if((w1-w2)==1||(w1-w2)==-1){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            else{
                printf("00");
            }
        }
        else{
            printf("000");
        }
    }
    else{
        printf("0000");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
