#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,b1,b2;
    char c1,c2;
    scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
    if(a1==a2){
        printf("1");
        if(b1==b2){
            printf("1");
            if((c1>='D'&&c2>='D')||(c1<='C'&&c2<='C')){
                printf("1");
                if(max(c1,c2)-min(c1,c2)==1)
                    printf("1");
                else
                    printf("0");
            }else{
                printf("00");
            }
        }else{
            printf("000");
        }
    }else{
        printf("0000");
    }
    printf("\n");
    return 0;
}
