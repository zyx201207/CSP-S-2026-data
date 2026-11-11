#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long a[500005];
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    long long cha;
    if (a[2]-a[1]>=0){
        cha=a[2]-a[1];
    }
    else{
        cha=a[1]-a[2];
    }
    int cnt=0;
    int d=cha;
    while (m>=cha){
        m-=cha;
        ++cnt;
        cha+=d;
    }
    printf("%d",cnt);
    return 0;
}
