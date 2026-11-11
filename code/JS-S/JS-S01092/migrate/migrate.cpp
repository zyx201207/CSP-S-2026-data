#include <bits/stdc++.h>
using namespace std;
inline int read();
inline void wt(int);
struct P{
    int v,w;
    const bool operator>(const P& a)const{
        return w > a.w;
    }
};
vector<P>g[2000005];
int c,t,n,d,p[2000005],dis[2000005],cnt[2000005],cnts;
queue<P> q;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c = read(),t = read();
    while(t--){
        n = read(),d = read();
        for(int i = 1;i <= n;i++) p[i] = read();
        for(int i = 1;i <= n;i++){
            for(int j = 1 ;j < i;j++){
                if(i - j == 1 || abs(p[i] - p[j]) <= d) g[j].push_back({i,abs(p[i] - p[j])});
            }
        }
        for(int i = 1;i <= n;i++){
            memset(dis,0x3f,sizeof(dis));
            memset(cnt,0,sizeof(cnt));
            dis[i] = 0;
            cnts = 0;
            q.push({i,0});
            while(!q.empty()){
                P frnt = q.front();
                dis[frnt.v] = frnt.second;
                q.pop();
                for(auto nd : g[frnt.v]){
                    if(dis[nd.v] == dis[frnt.v] + 1) cnt[nd.v]++;
                    else if(!vis[nd]){
                        q.push({nd.v,dis[nd.v]});
                        vis[nd] = 1;
                    }
                }
            }
            for(int i = 1;i <= n;i++){
                if(cnt[i] == 2) cnts++;
            }
        }

        wt(cnts / 2),putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
inline int read(){
    register int r;register bool f = 1;register char c;
    while((c = getchar()) && !isdigit(c)) if(c == '-') f ^= 1;
    r = (c ^ 48);
    while((c = getchar()) && isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48);
    return r * (f ? 1 : -1);
}
inline void wt(int n){
    if(n < 0) putchar('-'),n = -n;
    if(n > 9) wt(n / 10);
    putchar(n % 10 + 48);
}
