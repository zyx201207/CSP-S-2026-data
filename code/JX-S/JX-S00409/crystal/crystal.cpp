#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500000+5;

ll n,m,a[maxn],b[maxn],bs[maxn],ans,res=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("name/crystal/crystal4.in","r",stdin);

    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }

    sort(&a[1],&a[n+1]);

    b[n]=0,bs[0]=0;
    for(ll i=n-1;i;--i){
        b[i]=a[i+1]-a[i];
    }
    for(ll i=1;i<=n;++i){
        bs[i]=bs[i-1]+b[i];
    }
    ans=1;
    int tm=m;
    int j=0;
    for(int i=1;i<=n-1 && j<=n-1;++i){
        while(tm < b[i]*(i-j)||tm<0){
            --ans;
            if(tm+(bs[i]-bs[j])<m)
                tm+=(bs[i]-bs[j]);
            else tm=m;
            ++j;
            if(i<=j)break;
        }
        if(i<=j)continue;
        tm-=b[i]*(i-j);
        ++ans;
        res=((res>=ans)?res:ans);
        //printf("[%d,%d)\nans%d,\t tm%d,  \ta%d,\tb%d,\tbs%d",i,j,ans,tm,a[i],b[i],bs[i]);
    }
    printf("%lld",res);

    fclose(stdin);fclose(stdout);
}
