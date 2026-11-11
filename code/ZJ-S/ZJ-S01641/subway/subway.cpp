#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510,M = 5e5 + 10;
int n,m,d,Q,c,w[M];
ll ans[M];
int x,y;
struct line{
    vector<pair<int,int>> st;
    int len;
}a[N];
struct station{
    vector<pair<int,int>> pass;
}b[M];
void dfs(int now,ll spend,int l)
{
    if(spend > ans[now]) return;
    ans[now] = spend;
    if(now == y) return;
    int h = b[now].pass.size();
    for(int i = 0;i < h;i++){
        int by = b[now].pass[i].first;
        if(by == l) continue;
        for(auto j : a[by].st){
            dfs(j.first,spend + b[now].pass[i].second + j.second,by);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> a[i].len;
        for(int j = 1;j <= a[i].len;j++){
            int p,k;
            cin >> p >> k;
            a[i].st.push_back({p,k});
            b[p].pass.push_back({i,k});
        }
    }
    while(Q--){
        cin >> x >> y;
        for(int i = 1;i <= m;i++) ans[i] = LONG_LONG_MAX;
        dfs(x,0,0);
        cout << ans[y] + w[x] + w[y] << "\n";
    }
    return 0;
}
