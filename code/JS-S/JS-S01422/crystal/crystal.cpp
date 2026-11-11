#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN], sum[MAXN], M;
int N, ans;
int bound(int x){
    int l=1, r=x, mid=0;
    while(l<r){
        mid=(l+r)/2;
        if(1ll*(x-mid+1)*a[x]<=M+sum[x]-sum[mid-1]){r=mid;}
        else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &N, &M);
    for(int i=1; i<=N; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+N+1);
    for(int i=1; i<=N; i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1; i<=N; i++){
        ans=max(ans, i-bound(i)+1);
    }
    printf("%d\n", ans);
    return 0;
}
