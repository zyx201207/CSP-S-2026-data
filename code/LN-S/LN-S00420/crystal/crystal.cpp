#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const ll inf = 1e18;
int n, cnt, head = 1;
ll m, a[N], sum;
int main(){
    //freopen("crystal4.in", "r", stdin);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        sum += (i-head) * (a[i]-a[i-1]);
        while(sum > m) sum -= a[i]-a[head++];
        cnt = max(cnt, i-head+1);
    }
    printf("%d", cnt);
return 0;
}
