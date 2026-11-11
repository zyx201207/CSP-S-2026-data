#include<cstdio>
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s11,c2,s21;
    char s12,s22;
    scanf(" %d %d %c %d %d %c",&c1,&s11,&s12,&c2,&s21,&s22);
    if(c1==c2){
        if(s11==s21){
            bool isl1=(s12<='C'),isl2=(s22<='C');
            if(isl1==isl2){
                if(s12-s22==1||s22-s12==1){
                    puts("1111");
                }else{
                    puts("1110");
                }
            }else{
                puts("1100");
            }
        }else{
            puts("1000");
        }
    }else{
        puts("0000");
    }
    return 0;
}
