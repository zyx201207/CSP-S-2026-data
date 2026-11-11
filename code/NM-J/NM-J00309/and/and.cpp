#include<bits/stdc++.h>
using namespace std;
long long q,a[35],z,x[200005],e;
bool cmp(long long q,long long z){
    long long w,s;
    for(int i=1;i<=30;i++){//a[i+1]-q;
        if(q>=a[i]&&q<=a[i+1]) w=min(q-a[i],a[i+1]-q);
        if(z>=a[i]&&z<=a[i+1]) s=min(z-a[i],a[i+1]-z);//a[i+1]-z;
    }
    if(w<s) return q<z;
    else if(w=s&&q<z) return q<z;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&q,&z);
    for(int i=1;i<=30;i++){
        a[i]=pow(2,i);
    }
    for(int i=1;i<=q;i++){
        scanf("%lld",&x[i]);
    }
    sort(x+1,x+1+q,cmp);
    e=x[q];
    for(int i=q;i>q-z;i--){
        e=e&x[i];
    }
    printf("%lld",e);
    fclose(stdin);
    fclose(stdout);
}
