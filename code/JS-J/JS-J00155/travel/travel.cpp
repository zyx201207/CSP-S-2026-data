#include<cstdio>
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,a3,b1,b2,b3;
    a1=getchar()*10-528+getchar();
    getchar();
    a2=getchar()*10-528+getchar();
    a3=getchar()-64;
    getchar();
    b1=getchar()*10-528+getchar();
    getchar();
    b2=getchar()*10-528+getchar();
    b3=getchar()-64;
    const bool f1=a1==b1;
    const bool f2=a2==b2;
    const bool f3=(a3<=3)^(b3>=4);
    const bool f4=(a3-b3)==1||(a3-b3==-1);
    putchar(f1|48);
    putchar((f1&&f2)|48);
    putchar((f1&&f2&&f3)|48);
    putchar((f1&&f2&&f3&&f4)|48);
    return 0;
}
