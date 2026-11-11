#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
struct node{
    int lst,x;
    bool operator < (const node &ot) const{
        return lst < ot.lst;
    }
}b[M];
int a[N],ans[M],cnt[M],add[M];
vector<int> id[M];
void solve(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        id[a[i]].pb(i);
        cnt[a[i]]++;
        b[a[i]].lst = max(b[a[i]].lst,i);
    }
    for(int i = 1;i <= m;i++) b[i].x = i;
    sort(b + 1,b + m + 1);
    for(int i = 1;i <= m;i++){
        for(auto j : id[b[i].x]){
            if(j != b[i].lst) add[b[i].lst] += add[j];
            // cout << add[10] << " ";
            // if(b[i].x == 1) cout << add[j] << " ";
        }
        ans[b[i].x] = add[b[i].lst] + cnt[b[i].x];
        add[b[i].lst + 1] += cnt[b[i].x] + add[b[i].lst];
    }
    // cout << "\n";
    for(int i = 1;i <= m;i++) cout << ans[i] << " ";
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1;
    while(T--) solve();
}

// expect 100 pts