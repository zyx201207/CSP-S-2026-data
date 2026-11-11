#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
void solve(int x){
    vector<int>cnt[3005],v;
    for (int i = x;i <= n;i++){
        while(cnt[a[i]].size() >= 1){
            int xx = v[v.size()-1];
            cnt[a[xx]].pop_back();
            v.pop_back();
        }
        cnt[a[i]].push_back(i);
        v.push_back(i);
        //cout << 1;
    }
    for (int i = 1;i <= m;i++){
        ans[i] += cnt[i].size();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        solve(i);
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
