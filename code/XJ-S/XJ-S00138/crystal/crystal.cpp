#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],tot,ans=1,now;
struct Node{
    int u,val;
    friend bool operator<(const Node &p,const Node &q){
        return p.val > q.val;
    }
};
priority_queue<Node> q;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    q.push({1,a[1]});
    now=a[1];
    for (int i=2;i<=n;i++){
        if (m >= tot+(a[i]-now)*q.size()) {
            tot+=(a[i]-now)*q.size();
            q.push({i,a[i]});
            now=a[i];
            ans=max(ans,(int)q.size());
        }
        else{
            while (!q.empty() && m < tot+(a[i]-now)*q.size()){
                tot-=(now-q.top().val);
                q.pop();
            }
            if (m < tot+(a[i]-now)*q.size()) continue;
            tot+=(a[i]-now)*q.size();
            q.push({i,a[i]});
            now=a[i];
            ans=max(ans,(int)q.size());
        }
    }
    cout << ans << '\n';
    return 0;
}