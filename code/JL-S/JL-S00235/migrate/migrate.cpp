#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    char ch = getchar_unlocked();
    int sign = 1,value = 0;
    while(!isdigit(ch)){
        if(ch == '-')sign = -1;
        ch = getchar_unlocked();
    }
    while(isdigit(ch)){
        value = value * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return sign * value;
}
const int N = 2000238;
int C,T,n,d;
int a[N];
int dis[N],cnt[N],b[N];
bool chk(int p1,int p2){return (a[p2] - a[p1] <= d);}
void solveA(){
    if(n == 1){
        printf("0\n");
        return;
    }
    int dist = a[2] - a[1];
    int k = d / dist;
    if(k == 0 || k == 1){
        printf("0\n");
        return;
    }
    int ans = 0;
    for(int i = k - 1;i<=k - 1;i++){
        int len = k + i;
        if(len >= n)continue;
        ans += (n - len);
    }
    printf("%lld\n",ans);
}
void solve(){
    if(n == 1){
        printf("0\n");
        return;
    }
    int ans = 0;
    for(int p = 1;p<=n;p++){
        for(int i = 0;i<=n;i++)dis[i] = cnt[i] = b[i] = 0;
        cnt[p] = 1;
        b[0] = 1;
        int now = 0;
        for(int r = p + 1,l = p;r<=n;r++){
            while(!chk(l , r)){
                b[dis[l]] -= cnt[l];
                l++;
                while(b[now] == 0 && now <= n)now++;
            }
            if(now == n + 1)break;
            cnt[r] = b[now];
            dis[r] = now + 1;
            if(b[now] == 2)ans++;
            b[dis[r]] += cnt[r];
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    C = read(),T = read();
    while(T--){
        n = read(),d = read();
        for(int i = 1;i<=n;i++)a[i] = read();
        if((C == 0) || (C >= 11 && C <= 12))solveA();
        else solve();
    }
    return 0;
}
/*
warring : n == 1
warring : cant arrive
*/
