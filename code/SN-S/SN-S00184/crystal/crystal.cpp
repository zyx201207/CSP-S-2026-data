#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
void work() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &tmp : a) {
        cin >> tmp;
        sum += tmp;
        cnt[tmp]++;
    }
    vector<pair<int,int>> pr;
    for (auto tmp : cnt){
        pr.push_back(tmp);
    }
    //for (auto tmp:pr) {
    //    cerr << tmp.first << ' ' << tmp.second << endl;
    //}
    sort(pr.begin(), pr.end());
    
    // for (int i = 1; i < pr.size(); i++) {
    //     num += pr[i - 1].second;
    //     cost += num * (pr[i].first - pr[i - 1].first);
    //     //cerr << cost << endl;
    //     while(cost > m) {
    //         num -= pr[bg].second;
    //         cost -= pr[bg].second * (pr[i].first - pr[bg].first);
    //         lans -= pr[bg].second;
    //         bg++;
    //     }
    //     lans += pr[i].second;
    //     ans=max(ans , lans);
    // }
    {
    vector<int> a;
    for (auto tmp:pr) {
        for (int i = 1; i <= tmp.second; i++) {
            a.push_back(tmp.first);
        }
    }
    int cost = 0, ans = 0, lans = 1, num = 1, l = 0;
    for (int r = 1; r < n; r++) {
        cost += num * (a[r] - a[r - 1]);
        while (cost > m){
            cost -= a[r] - a[l];
            lans--;
            num--;
            l++;
        }
        lans++;
        num++;
        ans = max(ans,lans);
    }
    cout << ans << endl;}
}
}
signed main() {
    freopen("crystal.in", "r",stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    Qaaxaap::work();
    return 0;
}
    // vector<int> tms;
    // for(auto lf : pr){
    //     int fl = lf.first;
    //         int ans = 0, tm = 0;//, fl = pr[0].first;
    //     for (auto tmp : pr) {
    //         int x = tmp.first, y = tmp.second;
    //         tm += qabs(x - fl) * y;
    //     }
    //     tms.push_back(tm);
    // }
    // int mi = *min_element(tms.begin(), tms.end());
    // cerr << mi << endl;
    // int cnt1 = 0, ed;
    // for (int i = 0; i < tms.size() - 1; i++) {
    //     if (tms[i] == mi) {
            
    //         ed = i;
    //         break;
    //     }
    //     if (tms[i] < tms[i + 1])
    //     cnt1 = 1;
    // }
    // ed++;
    // for (int i = ed; i < tms.size(); i++) {
    //     if (tms[i - 1] > tms[i])
    //     cnt1 = 1;
    // }
    // cerr  <<  cnt1 << endl;

