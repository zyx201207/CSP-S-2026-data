#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;
int n, m, ans;
long long a[N];
deque <int> q;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    int i = 1, j = 1;
    long long cost = 0;
    do{
        while(j <= i && cost > m){
            cost -= a[i] - a[j++];
        }
        //printf("i:%d j:%d cost:%lld\n", i, j, cost);
        ans = max(ans, i - j + 1);
        i++;
        cost += (i - j) * (a[i] - a[i-1]);
        //printf("i:%d j:%d cost:%lld\n", i, j, cost);
    }while(i <= n);
    printf("%d", ans);
    return 0;
}
