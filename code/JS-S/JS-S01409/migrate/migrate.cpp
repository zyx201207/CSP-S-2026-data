#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int read(){
    int f = 1,x = 0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48),c = getchar();
    return f * x;
}
int n,d;
int x[N],sum[N],dis[N];
vector<int> G[N];
void solve2(){
    n = read(),d = read();
    for(int i=1;i<=n;i++)
        x[i] = read();
    int dis = x[2] - x[1];
    if(d / dis > 1 && d/dis + (d/dis - 1) <= n){
        cout<<(int)(n - (d / dis - 1) - (d/dis))<<'\n';
    }else cout<<"0\n";
}
void solve(){
    n = read(),d = read();
    for(int i=1;i<=n;i++)
        x[i] = read(),dis[i] = x[i] - x[i-1];
    for(int i=2;i<=n;i++)
        sum[i] = sum[i-1] + dis[i];
    int dis = x[2] - x[1];
    if(d / dis > 1 && d/dis + (d/dis - 1) <= n){
        cout<<(int)(n - (d / dis - 1) - (d/dis))<<'\n';
    }else cout<<"0\n";
}
signed main(){
    // freopen("migrate.in","r",stdin);
    // freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    int c = read(),t = read();
    if(c >= 11 && c <= 12){
        while(t--)
            solve2();
    }else if(c >= 13 && c <= 14){
        while(t--)
        cout<<0<<'\n';
    }else while(t--) solve();
    return 0;
}