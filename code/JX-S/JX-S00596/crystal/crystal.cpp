#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10, inf = 1e18;
int n, m, a[N], ans, maxa, mina = inf;
bool op = true;
int d;
bool op2 = true;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
        if(a[i] != i){
            op = false;
        }
        if(i == 2) d = a[i] - a[i - 1];
        if(i != 1 && a[i] - a[i - 1] != d){
            op2 = false;
        }
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    sort(a + 1, a + n + 1);
    int mm = m;
    if((maxa - mina) * n <= m){
        printf("%lld\n", n);
        return 0;
    }
    if(n <= 5000){
        for(int i = 1; i <= n; i ++){
            m = mm;
            int cnt = 1;
            int l = i - 1, r = i + 1;
            while(true){
                bool flag = false;
                int pos = -1;
                int mi = inf;
                if(l >= 1 && a[i] - a[l] <= m && a[i] - a[l] < mi){
                    mi = a[i] - a[l];
                    pos = 0;
                    flag = true;
                }
                if(r <= n && a[r] - a[i] <= m && a[r] - a[i] < mi){
                    mi = a[r] - a[i];
                    pos = 1;
                    flag = true;
                }
                if(!flag) break;
                m -= mi;
                cnt ++;
                if(pos == 0){
                    l --;
                    // printf("----> %lld l\n", i);
                }
                else if(pos == 1){
                    r ++;
                    // printf("----> %lld r\n", i);
                }
            }
            ans = max(ans, cnt);
        }
        printf("%lld\n", ans);
        return 0;
    }
    if(op){
        int mid = n / 2 + 1;
        int cnt = 1;
        int l = mid - 1, r = mid + 1;
        while(true){
            if(l < 1){
                printf("%lld\n", cnt);
                return 0;
            }
            if((a[mid] - a[l]) * 2 <= m){
                m -= (a[mid] - a[l]) * 2;
                l --;
                r ++;
                cnt += 2;
            }
            else if((a[mid] - a[l]) <= m){
                cnt ++;
                printf("%lld\n", cnt);
                return 0;
            }
            else{
                return 0;
            }
        }
        return 0;
    }
    if(op2){
        int mid = n / 2 + 1;
        int cnt = 1;
        int l = mid - 1, r = mid + 1;
        while(true){
            if(l < 1){
                printf("%lld\n", cnt);
                return 0;
            }
            if((a[mid] - a[l]) * 2 <= m){
                m -= (a[mid] - a[l]) * 2;
                l --;
                r ++;
                cnt += 2;
            }
            else if((a[mid] - a[l]) <= m){
                cnt ++;
                printf("%lld\n", cnt);
                return 0;
            }
            else{
                return 0;
            }
        }
        return 0;
    }
    return 0;
}