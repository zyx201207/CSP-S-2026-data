#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n , m;
    scanf("%d %d",&n,&m);
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,greater<int>());
    int t = 1;
    long long ans = a[t];
    m--;
    while(m--){
        t++;
        ans &= a[t];
    }
    printf("%lld",ans);
    return 0;
}
