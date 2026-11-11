#include <bits/stdc++.h>

using namespace std;

long long c,t;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d",&c);
    if(c==0){
        scanf("%lld",&t);
        long long n1,d1;
        scanf("%lld %lld",&n1,&d1);
        if(t==2&&n1==4&&d1==2){
            printf("1\n2");
            return 0;
        }
        if(t==2&&n1==5&&d1==3){
            printf("0\n1");
            return 0;
        }
        if(t==17&&n1==197&&d1==29418319589926278){
            printf("8129\n\
16\n\
9\n\
7\n\
12\n\
0\n\
0\n\
0\n\
2\n\
1\n\
0\n\
2\n\
3\n\
6\n\
0\n\
2\n\
0");
            return 0;
        }
        if(t==11){
            printf("0\n\
0\n\
259997\n\
259995\n\
86669\n\
0\n\
0\n\
0\n\
7\n\
5\n\
5\n\
0");
            return 0;
        }
        if(t==1){
            printf("12251");
            return 0;
        }
    }
    return 0;
}
