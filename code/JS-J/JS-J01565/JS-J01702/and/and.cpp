#include<bits/stdc++.h>
using namespace std;
int m, n;
struct node{
    long long v;
    int num;
}a[200020];
int f(long long v){
    int cnt = 0;
    while(v > 0){
        cnt += v % 2;
        v /= 2;
    }
    return cnt;
}
bool cmp(const node a, const node b){
    if(a.num == b.num) return a.v > b.v;
    return a.num > b.num;
}
long long ans = 0;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i].v);
        a[i].num = f(a[i].v);
    }
    sort(a + 1, a + n + 1, cmp);
    ans = a[1].v;
    for(int i = 1; i <= m; i++){
        ans = ans & a[i].v;
    }
    printf("%lld", ans);
    return 0;
}
