#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long a[maxn];
int n , m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i < n ; i++) cin >> a[i];
    if(m == 1){
        long long ans = -1;
        for(int i = 1 ; i <= n ; i++)
            ans = max(a[i],ans);
        printf("%lld",ans);
        return 0;
    }else if(m == 2){
        long long ans = -1;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                if(i == j) continue;
                else ans = max(a[i] & a[j] , ans);
    }

    sort(a+1 , a+1+n);
    long long tmp[maxn];
    for(int i = 1 ; i <= n ; i++)
        tmp[i+1] = a[i] & a[i+1];

    long long ans = -1;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            if(i == j) continue;
            else ans = max(tmp[i] & tmp[j] , ans);

    printf("%lld",ans);
    return 0;
}


