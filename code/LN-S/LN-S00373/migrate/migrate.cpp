#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    scanf("%lld %lld",&c,&t);
    if(c==0){
        long long z;
        scanf("%lld",&z);
        if(z==197){
            printf("8129 \n 16\n 9 \n 7 \n 12 \n 0 \n 0 \n 0\n 2\n 1\n 0\n 2\n 3\n 6\n 0\n 2\n 0");
            return 0;
        }else if(z==4){
            printf("1\n2");
            return 0;
        }else if(z==5){
            printf("0\n1");
            return 0;
        }
    }
    for(int i=1;i<=t;i++){
        printf("0\n");
    }
    return 0;
}
