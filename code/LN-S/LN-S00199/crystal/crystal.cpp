#include<bits/stdc++.h>
using namespace std;

long long n,m,tmpin[1145140];
struct cry{
    long long n,num=0;
    bool ablehec=false;
}a[1145140];

bool acmp(cry a,cry b){
    return a.num<b.num;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&tmpin[i]);
    }
    sort(tmpin+1,tmpin+1+n);
    tmpin[0]=-12345678901234;
    long long crynum=0;
    for(int i=1;i<=n;i++){
        printf("%lld\n",crynum);
        if(tmpin[i]!=tmpin[i-1]){
            for(int pw=1;pw<=20;pw++){
                if(n+1+tmpin-find(tmpin+1,tmpin+n+1,tmpin[i]*pow(2,pw))){
                //if(ablefind(tmpin[i]*pow(2,npw),1,n))){
                    printf("find%lld*2^%lld(%lld)\n",tmpin[i],pw,n+1+tmpin-find(tmpin+1,tmpin+n+1,tmpin[i]*pow(2,pw)));
                    for(int npw=1;npw<pw;npw++){
                        crynum++;
                        a[crynum].n=tmpin[i]*pow(2,npw);
                        a[crynum].num=0;
                    }
                    break;
                }
            }
            crynum++;
            a[crynum].n=tmpin[i];
            a[crynum].num=1;
        }else{
            a[crynum].num++;
        }
    }
    sort(a+1,a+1+crynum,acmp);
    for(int st=1;st<=crynum;st++){
        printf("%lld:%lld\n",a[st].n,a[st].num);
    }
    printf("为什么还有+1操作，不会了qaq\n");
    printf("I AK IOI\n");
    return 0;
}
