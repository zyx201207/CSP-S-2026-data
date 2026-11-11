#include <bits/stdc++.h>
using namespace std;

int n,a[999999];
char c[209999];
long long ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i],&c[i]);
    }
    int L=1,R=n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cnt=cnt+a[i]+0LL;
    }
    while(cnt>0){
        if(!a[L])
            L++;
        if(!a[R])
            R--;
        if(c[L]!=c[R])
            ans++;
        a[L]--,a[R]--,cnt-=2;
    }
    printf("%lld",ans);
}
