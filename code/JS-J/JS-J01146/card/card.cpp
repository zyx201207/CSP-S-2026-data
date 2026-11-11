#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read();
inline void wt(int);
int n,m,a[500005],cnt[500005],vis[500005],k;
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n = read(),m = read();
    for(register int i = 1;i <= n;++i) a[i] = read();
    for(register int i = 1;i <= n;++i){
        for(register int j = i;j <= n;++j){
            k = a[j];
            if(!vis[k]){
                s.push(k);
                vis[k]++;
            }else{
                while(s.top() != k) vis[s.top()]--,s.pop();
            }
        }
        for(register int j = i;j <= n;++j){
            if(vis[a[j]]) cnt[a[j]]++,vis[a[j]] = 0;
        }
    }
    for(register int i = 1;i <= m;++i) wt(cnt[i]),putchar(' ');
    fclose(stdin);
    fclose(stdout);
    return 0;
}

inline int read(){
    register int r;register bool f = 1;register char c;
    while((c = getchar()) && !isdigit(c)) if(c == '-') f^=1;
    r = (c ^ 48);
    while((c = getchar()) && isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48);
    return r * (f ? 1 : -1);
}
inline void wt(int n){
    if(n < 0) putchar('-'),n = -n;
    if(n > 9) wt(n / 10);
    putchar(n % 10 + 48);
}
