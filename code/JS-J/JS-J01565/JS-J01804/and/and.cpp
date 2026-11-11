#include <bits/stdc++.h>
using namespace std;
int n, m;
struct number{
    long long x;
    int sum;
};
number a[200010];
int f(long long x){
    int cnt=0;
    while(x != 0){
        cnt += x & 1;
        x = (x >> 1);
    }
    return cnt;
}
bool cmp(number q, number w){
    if(q.sum != w.sum)
        return q.sum > w.sum;
    return q.x > w.x;
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin >> n >> m;
    long long maxn=0, ans=0;
    for(int i=1;i<=n;i++){
        cin >> a[i].x;
        maxn = max(a[i].x,maxn);
        a[i].sum = f(a[i].x);
    }
    if(m == 1){
        cout << maxn;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ans = a[1].x & a[2].x;
    for(int i=2;i<=m;i++){
        ans = ans & a[i].x;
    }
    cout << ans;

    return 0;
}

