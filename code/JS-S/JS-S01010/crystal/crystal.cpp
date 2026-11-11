#include<bits/stdc++.h>
using namespace std;
long long a[500009];
long long n,m;
bool cmp(long long a,long long b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    /*for(int i=1;i<=n;i++){
        printf("%lld\n",a[i]);
    }*/
    long long last_num=a[1];
    for(long long i=2;i<=n;i++){
        if(m-(i-1)*(a[i]-last_num)>=0){
            m-=(i-1)*(a[i]-last_num);
            last_num=a[i];
        }
        else{
            printf("%lld",i-1);
            return 0;
        }
    }
    printf("%lld",n);
    return 0;
}