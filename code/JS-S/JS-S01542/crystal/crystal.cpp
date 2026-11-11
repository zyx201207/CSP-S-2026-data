#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

int n, s, mx;
long long a[500100], m, pre_sum[500100];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1;i <= n;++i){
        scanf("%lld", a+i);
    }
    sort(a+1, a+n+1);
    for(int i = 1;i <= n;i++){
        pre_sum[i] = pre_sum[i-1] + a[i];
        int l = 0, r = i;
        while(l + 1 < r){
            int mid = (l + r) >> 1;
            if((i - mid + 1) * a[i] - pre_sum[i] + pre_sum[mid-1] > m) l = mid;
            else r = mid;
        }
        mx = max(mx, i-r+1);
    }
    printf("%d", mx);
}
