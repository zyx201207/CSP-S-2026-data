#include<bits/stdc++.h>
using namespace std;

struct node{
    long long cha;
    long long hao;
};

bool fun(long long a1,long long a2){
    return a1<a2;
}
/*
long long solve(long long a[500005],node b[500005],long long n,long long m){
    long long mi=999999999,x=0;
    for(int i=1;i<=n-1;i++){
        if(b[i].cha<mi){
            if(b[i].can){
                mi=b[i].cha;
                x=i;
            }else{

            }
        }
    }
    return x;
}
*/

long long suan(long long x[500005],long long i){
    long long sum=0;
    sum+=x[i]*i;
    for(long long j=1;j<=i;j++){
        sum-=x[j-1];
    }
    return sum;
}

long long a[500005]={};
node b[500005]={};
long long x[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,fun);
    x[0]=0;
    long long jizhun=0,dian=0;
    for(long long i=1;i<=n-1;i++){
        b[i].cha=a[i+1]-a[i];
        b[i].hao=i;
        x[i]=b[i].cha+x[i-1];
        long long y=suan(x,i-1);
        long long z=suan(x,i);
        if(y<=m&&z>m){
            jizhun=a[i];
            dian=i;
        }
    }
    for(long long i=dian;i<=n;i++){
        if(a[i+1]!=jizhun){
            printf("%lld",i);
            break;
        }
    }
//    printf("\n\n%lld\n\n",jizhun);
    return 0;
}
