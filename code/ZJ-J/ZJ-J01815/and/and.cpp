#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050];
long long res;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    if(m==1){
        sort(a+1,a+n+1);
        printf("%d",a[n]);
        return 0;
    }
    if(n==m){
        res=a[1];
        for(int i=2;i<=n;++i)res&=a[i];
        printf("%lld",res);
        return 0;
    }
    sort(a+1,a+n+1);
    res=a[n];
    for(int i=n-1;i>=n-m;--i){
        res&=a[i];
    }
    printf("%lld",res);
    return 0;
}
