#include <bits/stdc++.h>
using namespace std;
int c1,c2;
bool checka,checkb,checkc,checkd;
char a[8],b[8];
int main(){
    //02 01A 02 01B
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    scanf("%2d",&c1);
    scanf("%s",a);
    scanf("%2d",&c2);
    scanf("%s",b);

    if(c1==c2){
        checka = true;
    }else if(c1!=c2){
        printf("0000");
        return 0;
    }
    if(a[0]==b[0]&&a[1]==b[1]){
        checkb = true;
    }else{
        printf("1000");
        return 0;
    }
    if(a[2]<='C'&&a[2]>='A'){
        if(b[2]>='D'&&b[2]<='E'){
            printf("1100");
            return 0;
        }
        else{
            if(a[2]+1==b[2]){
                printf("1111");
                return 0;
            }
            else if(a[2]-1==b[2]){
                printf("1111");
                return 0;
            }
            else{
                printf("1110");
                return 0;
            }
        }
    }
    else if(a[2]>='D'&&a[2]<='E'){
        if(b[2]>='A'&&b[2]<='C'){
            printf("1100");
            return 0;
        }
        else{
            if(a[2]+1==b[2]){
                printf("1111");
                return 0;
            }
            else if(a[2]-1==b[2]){
                printf("1111");
                return 0;
            }
            else{
                printf("1110");
                return 0;
            }
        }
    }
    return 0;
}
