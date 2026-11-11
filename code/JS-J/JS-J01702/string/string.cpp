#include<bits/stdc++.h>
using namespace std;
int n;
long long ans = 0, x[200020];
struct node{
    long long s, t;
    char c;
}a[200020], b[200020];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    long long start = 1;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> a[i].c;
        a[i].s = start;
        start += x[i];
        a[i].t = start;
    }
    int N = start;
    start = 1;
    for(int i = n; i >= 1; i--){
        b[n - i + 1].s = start;
        start += x[i];
        b[n - i + 1].c = a[i].c;
        b[n - i + 1].t = start;
    }
    int i = 1, j = 1;
    long long k = 1;
    while(i <= n && j <= n && k <= N){
        long long y = min(a[i].t, b[j].t);
        if(a[i].c != b[j].c) ans += y - k;
        k = y;
        if(a[i].t < b[j].t) i++;
        if(a[i].t > b[j].t) j++;
        if(a[i].t == b[j].t) i++, j++;
    }
    ans /= 2;
    printf("%lld", ans);
    return 0;
}
