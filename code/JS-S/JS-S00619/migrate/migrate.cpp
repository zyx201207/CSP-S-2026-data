#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n,d;
    cin>>n>>d;
    vector<int> x(n+5);
    for (int i=1;i<=n;i++) {
        cin>>x[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        queue<array<int,2>> que;
        que.push({i,0});
        vector<int> dist(n+5,INT_MAX),num(n+5);
        dist[i]=0;num[i]=1;
        while (!que.empty()) {
            int a=que.front()[0];
            int dis=que.front()[1];
            que.pop();
            for (int j=a+1;j<=n;j++) {
                if (x[j]-x[a]>d) {
                    break;
                }
                if (dist[j]>dis+1) {
                    dist[j]=dis+1;
                    num[j]=num[a];
                } else {
                    if (dist[j]==dis+1) {
                        num[j]++;
                    }
                    continue;
                }
                que.push({j,dis+1});
            }
        }
        for (int j=i;j<=n;j++) {
            if (num[j]==2) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--) {
        solve();
    }
    return 0;
}
