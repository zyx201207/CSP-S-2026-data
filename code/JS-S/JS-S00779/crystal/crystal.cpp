#include <bits/stdc++.h>
using namespace std;
const int N = 510000;
typedef long long ll;
int n, a[N], head, tail, ans;
ll m, cost;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    head=1;
    tail=1;
    ans=0;
    sort(a+1, a+n+1);
    a[0] = a[1];
    for(head=1;head<=n;head++){
        cost += (head-tail)*(a[head]-a[head-1]);
        // printf("[%d, %d] Cost=%lld\n", tail, head, cost);
        while(cost>m){
            cost -= (a[head]-a[tail]);
            tail++;
            // printf("[%d, %d] Cost=%lld\n", tail, head, cost);
        }
        ans = max(ans, head-tail+1);
    }
    printf("%d", ans);
    return 0;
}