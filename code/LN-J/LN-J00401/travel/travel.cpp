#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[13];
    for(int i=0;i<13;i++){
        scanf("%c",&a[i]);
    }
    if(a[0]!=a[7]||a[1]!=a[8]){
        printf("0000");
    }else if(a[3]!=a[10]||a[4]!=a[11]){
        printf("1000");
    }else if((a[5]<='C')!=(a[12]<='C')){
        printf("1100");
    }else if((a[5]-a[12]!=1)&&(a[12]-a[5]!=1)){
        printf("1110");
    }else{
        printf("1111");
    }
    return 0;
}
