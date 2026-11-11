#include<bits/stdc++.h>
#define QwQ return 0
#define ll long long
using namespace std;

ll rd();
void rout(ll), out(ll);

const int N = 2e6+5;
int c, t;
int n;
ll d;
ll x[N];
ll duan[N];
ll num[N];
int nxt[N];

void dfs(int pos ,int step){
    if(step > duan[pos]) return;
    if(duan[pos]==1e18) num[pos] = 1, duan[pos] = step;
    else num[pos]++;
    for(int i=nxt[pos]; i>pos; i--){
        dfs(i, step+1);
    }
}


int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = rd();
    t = rd();
    while(t--){
        n = rd() , d= rd();
        ll ans=0;
        for(int i=1; i<=n; i++) x[i] = rd();
        int head = 1;
        for(int i=2; i<=n; i++)
            while(x[i] - x[head] > d) nxt[head++] = i-1;
        for(; head<n;) nxt[head++] = n;
        nxt[n] = 0;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++) duan[j] = 1e18;
            dfs(i, 0);
            for(int j=i+3; j<=n; j++)
                if(num[j] == 2) ans++;
        }
        out(ans);
        putchar(10);
    }
    QwQ;
}//rp++!




























ll rd(){
    ll x=0, w=1;
    char c=getchar_unlocked();
    while(!isdigit(c)){
        if(c == '-') w=-1;
        c=getchar_unlocked();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c^48);
        c=getchar_unlocked();
    }
    return x*w;
}

void rout(ll x){
    if(x > 9) rout(x/10);
    putchar(x%10^48);
}

void out(ll x){
    if(x < 0) putchar('-'), x = -x;
    rout(x);
}
