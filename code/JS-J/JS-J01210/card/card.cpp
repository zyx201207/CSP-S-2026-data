#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v;
vector<vector<int>> t1, t2;
int ans[300005], cnt[300005];
bool f[300005];
int bin(int x, int y){
    int l = 0, r = t1.size() - 1, mid;
    while (l < r){
        mid = l + (r - l) / 2;
        if (t1[x][mid] >= y)
            mid = r;
        else
            l = mid + 1;
    }
    return t1[x][l] == y ? l : -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    t1.resize(m + 1);
    t2.resize(m + 1);
    v.resize(n + 1);
    for (int i = 1;i <= n;i++)
        cin >> v[i];
    for (int i = 1;i <= n;i++){
        memset(cnt, 0, sizeof(cnt));
        memset(f, 0, sizeof(f));
        t1.clear();
        t2.clear();
        for (int j = i;j <= n;j++){
            cnt[v[i]]++;
            t1[v[i]].push_back(j);
            if (cnt[v[i]] > 1){
                t2[v[i]].push_back(j);
            }
        }
        for (int j = i;j <= n;){
            if (t1[v[j]].size() > 1){
            int k = bin(v[j], j);
            if (k != -1)
                //if (k < t2.size()){
                    j = t2[v[j]][j];
                    continue;
                //}
            }
            if (!f[v[i]]){
                ans[v[i]]++;
                f[v[i]] = 1;
            }
            j++;
        }
    }
    for (int i = 1;i <= m;i++)
        cout << ans[i] << " ";
    return 0;
}
