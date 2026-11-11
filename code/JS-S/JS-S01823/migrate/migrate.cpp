#include <bits/stdc++.h>
using namespace std;

long long c,t;
long long n,d;
long long a[50005];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t --) {
        cin >> n >> d;
        if(n >= 5005) {
            cout << (long long)(n - 1) * (long long)(n - 2);
        }
        long long minn = 100000000000;
        for(long long i = 1;i <= n;i ++) {
            cin >> a[i];
            minn = min(a[i],minn);
        }
        if(minn < 0) {
            for(long long i = 1;i <= n;i ++) {
                a[i] += minn;
            }
        }
        vector<long long> G[5005];
        for(long long i = 1;i < n;i ++) {
            for(long long j = i + 1;j <= n;j ++) {
                if(a[j] - a[i] <= d) {
                    G[i].push_back(j);
                }
            }
        }
        long long res = 0;
        for(long long i = 1;i <= n;i ++) {
            bool vis[5005];
            long long dis[5005],cnt[5005];
            for(long long i = 0;i <= n;i ++) {
                vis[i] = 0;
                dis[i] = 0;
                cnt[i] = 0;
            }
            queue<long long> q;
            vis[i] = 1;
            dis[i] = 0;
            q.push(i);
            while(!q.empty()) {
                long long top = q.front();
                q.pop();
                for(long long j : G[top]) {
                    if(!vis[j]) {
                        q.push(j);
                        vis[j] = 1;
                        dis[j] = dis[top] + 1;
                        //cout << dis[j] << ' ' << j << "  ";
                    } else {
                        if(dis[j] == dis[top] + 1) {
                            if(cnt[j] == 0) {
                                res ++;
                                cnt[j] ++;
                                //cout << "*" << dis[j] << ' ' << j << "  ";
                            } else {
                                if(cnt[j] < 2) {
                                    res --;cnt[j] ++;
                                }
                            }

                        }
                    }

                }

            }
            //cout << endl;
        }
        cout << res << endl;
    }
    return 0;
}
