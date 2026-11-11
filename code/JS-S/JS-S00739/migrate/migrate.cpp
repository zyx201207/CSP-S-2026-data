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

const int maxn = 2e6+7;
int c, T, n, dis[maxn];
ll d, x[maxn], cnt[maxn], ans;

vector <int> st, br;

void subtask1(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt[j] = 0, dis[j] = maxn;
        }
        dis[i] = 0, cnt[i] = 1;
        for(int j = i; j <= n; j++){
            if(cnt[j] == 2)
                ans++;
            for(int k = j+1; k <= n && x[k]-x[j] <= d; k++){
                if(dis[k] > dis[j]+1){
                    cnt[k] = cnt[j], dis[k] = dis[j]+1;
                }
                else if(dis[k] == dis[j]+1)
                    cnt[k] += cnt[j];
            }
        }
    }
    printf("%lld\n", ans);
}

void subtaskA(){
    ll tmp = x[2]-x[1];
    if(tmp >= d){
        printf("0\n");
        return;
    }
    if((__int128)d >= (__int128)(n-1) * (__int128)tmp){
        printf("0\n");
        return;
    }
    int l = 1, r = n-1, mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if((__int128)tmp*(__int128)mid <= (__int128)d && (__int128)d < (__int128)tmp*(__int128)(mid+1))
            break;
        else if((__int128)tmp*mid <= (__int128)d)
            l = mid+1;
        else r = mid-1;
    }
    printf("%lld\n", 1ll*(n-2*mid+1));
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while(T--){
        scanf("%d%lld", &n, &d);
        ans = 0;
        st.clear();
        br.clear();
        for(int i = 1; i <= n; i++){
            scanf("%lld", &x[i]);
        }
        if(n <= 5000){
            subtask1();
            continue;
        }
        else if(c == 11 || c == 12){
            subtaskA();
            continue;
        }
    }
    return 0;
}
