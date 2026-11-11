#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2000010;

int testcase, T;
int n;
LL d;
LL x[N];
int pre[N], nxt[N];
int llen[N], rlen[N];
LL lf[N], rf[N];

/*
    if i die:check llen init, rlen init
    then check
*/

void solve(){
    scanf("%d%lld", &n, &d);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    for(int i = 1, j = 0; i <= n; i++){
        while(j + 1 <= n && x[j + 1] - x[i] <= d) j++;
        nxt[i] = j;
    }
    for(int i = n, j = n + 1; i >= 1; i--){
        while(j - 1 >= 1 && x[i] - x[j - 1] <= d) j--;
        pre[i] = j;
    }
    /*for(int i = 1; i <= n; i++)
        printf("%d%c", nxt[i], " \n"[i == n]);
    for(int i = 1; i <= n; i++)
        printf("%d%c", pre[i], " \n"[i == n]);*/
    LL ans = 0;
    for(int L = 1, R; L <= n; L = R + 1){
        R = L;
        while(R + 1 <= n && x[R + 1] - x[R] <= d)
            R++;
        for(int i = L; i <= R; i++) // init
            llen[i] = rlen[i] = 0;
        for(int i = L; i <= R - 1; i++)
            llen[nxt[i]]++;
        for(int i = L + 1; i <= R; i++)
            rlen[pre[i]]++;

        //printf("cur:[%d,%d]\n", L, R);
        /*for(int i = L; i <= R; i++)
            printf("%d%c", llen[i], " \n"[i == R]);
        for(int i = L; i <= R; i++)
            printf("%d%c", rlen[i], " \n"[i == R]);*/

        for(int i = L; i <= R; i++) // init lf rf
            lf[i] = rf[i] = 0;
        for(int i = L; i <= R; i++){
            lf[i] = llen[i];
            if(nxt[pre[i]] == i)
                lf[i] += lf[pre[i]];
        }
        for(int i = R; i >= L; i--){
            rf[i] = rlen[i];
            if(pre[nxt[i]] == i)
                rf[i] += rf[nxt[i]];
        }
        for(int x = L + 1; x + 1 <= R - 1; x++){
            bool canl = nxt[pre[x]] == x + 1;
            bool canr = pre[nxt[x + 1]] == x;
            //printf("%d and %d\n", x, x + 1);
            if(canl && canr){
                ans += lf[pre[x]] * rf[nxt[x + 1]];
                //printf("lr %lld\n", lf[pre[x]] * rf[nxt[x + 1]]);
            }
            if(canl){
                ans += lf[pre[x]] * (rlen[x] - (pre[x + 1] == x));
                //printf("l %lld\n", lf[pre[x]] * (rlen[x] - (pre[x + 1] == x)));
            }
            if(canr){
                ans += (llen[x + 1] - (nxt[x] == x + 1)) * rf[nxt[x + 1]];
                //printf("r %lld\n", (llen[x + 1] - (nxt[x] == x + 1)) * rf[nxt[x + 1]]);
            }
            ans += (llen[x + 1] - (nxt[x] == x + 1)) * (rlen[x] - (pre[x + 1] == x));
            //printf("no %lld\n", (llen[x + 1] - (nxt[x] == x + 1)) * (rlen[x] - (pre[x + 1] == x)));
        }
    }
    printf("%lld\n", ans);
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &testcase, &T);
    while(T--){
        solve();
    }
    return 0;
}
