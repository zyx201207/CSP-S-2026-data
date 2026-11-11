#include<iostream>
#include<cstdio>
using namespace std;
long long n,j,h,t,z;
char c;
struct sj{
   long long a;
   char c;
}a[200500];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    t=n;
    h=1;
    for(j=1;j<=n;j++){
        scanf("%lld %c",&a[j].a,&c);
        a[j].c=c;
    }
    while(h<t){
        if(a[h].a>a[t].a){
            if(a[h].c!=a[t].c){
                z+=a[t].a;
                a[h].a-=a[t].a;
                t--;
            }
            else{
                a[h].a-=a[t].a;
                t--;
            }
        }
        else{
            if(a[h].c!=a[t].c){
                z+=a[h].a;
                a[t].a-=a[h].a;
                h++;
            }
            else{
                a[t].a-=a[h].a;
                h++;
            }
        }
    }
    printf("%lld",z);
    return 0;
}
