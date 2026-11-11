#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    char c = getchar();
    int f = 0, g = 1;
    while(c < '0' || c > '9'){
        if(c == '-') g = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        f = (f<<3)+(f<<1)+c-'0';
        c = getchar();
    }
    return f*g;
}

const int N = 2e6+10;
int fl[N], fr[N], n, d, x[N], dl[N], dr[N];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t;
    c = read();
    t = read();
    while(t--){
        n = read();
        d = read();
        for(int i = 1; i <= n; i++) x[i] = read();
        x[n+1] = x[n]+1;
        x[0] = x[1]-1;
        int nowl = 0, nowr = 0;
        for(int i = 1; i <= n; i++){
            fl[i] = 1;
            while(x[i] - x[nowl] > d) ++nowl;
            while(x[i+1] - x[nowr] > d) ++nowr;
            dl[i] = nowl;
            if(nowl == nowr) continue;
            fl[i] = fl[nowl]+fl[i]+(nowr-nowl-1);
        }

        nowr = n+1, nowl = n+1;
        
        for(int i = n; i >= 1; i--){
            fr[i] = 1;
            while(x[nowr] - x[i] > d) --nowr;
            while(x[nowl] - x[i-1] > d) --nowl;
            dr[i] = nowr;
            if(nowl == nowr) continue;
            fr[i] = fr[i]+fr[nowr]+(nowr-nowl-1);
        }

        int ans = 0;

        for(int i = 2; i <= n-2; i++){
            if(dl[i+2] == dl[i+1] || dr[i] == dr[i-1] || dr[i] <= i+1 || dl[i+1] >= i) continue;
            int cl = (dl[i] == dl[i+1]) * (fl[dl[i+1]]-1)+min(i,dl[i+2])-dl[i+1];
            int cr = (dr[i] == dr[i+1]) * (fr[dr[i]]-1)+dr[i]-max(i+1,dr[i-1]);
            ans = (ans+cl*cr);
        }

        cout << ans << "\n";
        for(int i = 0; i <= n+1; i++) dl[i] = dr[i] = fl[i] = fr[i] = x[i] = 0;
    }
}