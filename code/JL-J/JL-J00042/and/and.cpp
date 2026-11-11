#include<iostream>
#include<cstdio>
using namespace std;
long long x,m,n,z,j,s[10],i,l[40],mi[50],c;
bool s4=true;

struct ss{
    long long a;
    char c[40];
    bool t;
}a[200050];




int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    l[0]=1;
    for(j=1;j<=30;j++){
        l[j]=l[j-1]*2;
    }
    for(j=1;j<=n;j++){
        scanf("%lld",&a[j].a);
        c=a[j].a;
        for(i=30;c;i--){
            if(c>=l[i]){
                c-=l[i];
                a[j].c[i]='1';
                a[j].t=true;
                mi[i]++;
            }
        }
    }
    for(i=30;i>=0;i--){
    long long k,w;

    if(mi[i]>=m){
        for(k=1;k<=n;k++){
            if(a[k].t){
                if(a[k].c[i]=='1'){
                    k=k;
                }
                else{
                    a[k].t=false;
                    for(w=0;w<=30;w++){
                        if(a[k].c[w]=='1')mi[w]--;
                    }
                    }
                }
            }
        }
    }
    z=1073741823;
    for(j=1;j<=n;j++){
        if(a[j].t){
            z=(z&a[j].a);
        }

    }



    printf("%lld",z);
    return 0;
}
