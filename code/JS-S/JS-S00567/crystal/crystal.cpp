#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],q[500050],ans=0,maxn=1,tp=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    q[1]=0;
    for(int i=2;i<=n;i++){
        q[i]=a[i]-a[i-1];
    }
    for(int i=1;i<n;i++){
        ans--;
        tp-=(a[i+ans]-a[i-1]);
        while(tp<=m&&i+ans<n){
            ans++;
            tp+=ans*q[i+ans];
        }
        maxn=max(maxn,ans);
    }
    printf("%lld",maxn);
    return 0;
}
