#include <bits/stdc++.h>
using namespace std;
int n, m;
bool a[200010][35];
bool vis1[200010], vis2[200010];
int len[35];
vector <int> v[35];
void jxd(long long x, int y){
    string s = "";
    while(x > 0){
        if(x % 2 == 1){
            s += "1";
        } else {
            s += "0";
        }
        x = x / 2;
    }
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            v[i].push_back(y);
            len[i]++;
        }
    }

}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        jxd(x, i);
    }
    bool b = 1;
    for (int i = 34; i >= 0; i--){
        if(len[i] < m) continue;
        if(b){
            for (int j = 0; j < v[i].size(); j++){
                vis1[v[i][j]] = 1;
            }
            vis2[i] = 1;
            b = 0;
        } else {
            int sum = 0;
            vector <int> vec;
            for (int j = 0; j < v[i].size(); j++){
                if(vis1[v[i][j]]){
                    sum++;
                    vec.push_back(v[i][j]);
                }
            }
            if(sum >= m){
                for (int j = 1; j <= n; j++){
                    vis1[j] = 0;
                }
                for (int j = 0; j < vec.size(); j++){
                   vis1[vec[j]] = 1;
                }
                vis2[i] = 1;
            }
        }
    }
    long long x = 1, ans = 0;
    for (int i = 0; i <= 30; i++){
        if(vis2[i]){
            ans += x;
        }
        x = x * 2;
    }
    cout << ans;
    return 0;
}
