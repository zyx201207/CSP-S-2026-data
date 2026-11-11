#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

constexpr int N = 2e6 + 5;

LL read(){
    LL x = 0, f = 1; char c = getchar_unlocked();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar_unlocked();}
    while(c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c ^ 48); c = getchar_unlocked();}
    return x * f;
}

int cid, T, n, pre[N], nxt[N], cnt;
vector<int> vcl[N], vcr[N];
LL a[N], d;
void Clean(){
    for(int i = 1; i <= n; i++){
        a[i] = 0;
        vcl[i].clear(); vcr[i].clear();
    }
    n = d = cnt = 0;
}

void _main(){
    n = read(), d = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++){
        int l = i, r = n;
        while(l < r){
            const int mid = l + r + 1 >> 1;
            if(a[mid] - a[i] > d) r = mid - 1;
            else l = mid;
        }
        nxt[i] = l;
        vcl[l].push_back(i);
        l = 1, r = i;
        while(l < r){
            const int mid = l + r >> 1;
            if(a[i] - a[mid] > d) l = mid + 1;
            else r = mid;
        }
        pre[i] = l;
        vcr[l].push_back(i);
    }
    nxt[n] = n + 1;
    pre[1] = 0;
    for(int i = 1; i < n; i++){//i, i + 1
        int L = 0, R = 0;
        int l = pre[i], t = 0;
        if(nxt[l] == i + 1){
            t = i + 1;
            while(1){
                if(!vcl[t].empty()) L += vcl[t].back() - l + 1;
                t = l;
                if(nxt[pre[l]] != l || l == pre[l]) break;
                l = pre[l];
            }
        }
        else{
            if(!vcl[i + 1].empty()) L += max(0, min(i - 1, vcl[i + 1].back()) - *vcl[i + 1].begin() + 1);
        }
        l = nxt[i + 1];
        if(pre[l] == i){
            t = i;
            while(1){
                if(!vcr[t].empty()) R += l - *vcr[t].begin() + 1;
                t = l;
                if(pre[nxt[l]] != l || l == nxt[l]) break;
                l = nxt[l];
            }
        }
        else{
            if(!vcr[i].empty()) R += max(0, vcr[i].back() - max(i + 2, *vcr[i].begin()) + 1);
        }
        cnt += L * R;
    }
    printf("%d\n", cnt);
    Clean();
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cid = read(), T = read();
    while(T--) _main();
    return 0;
}