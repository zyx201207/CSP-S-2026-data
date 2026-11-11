#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <bitset>
#define ll long long

using namespace std;

const int maxn = 5e5+7;
int n, ans;
ll a[maxn], s[maxn], m;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i];
    for(int i = n; i >= 1; i--){
        int l = 1, r = i, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(a[i]*(i-mid+1) - (s[i]-s[mid-1]) <= m){
                ans = max(ans, i-mid+1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
