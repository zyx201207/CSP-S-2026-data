#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, L, sum, ans, a[200005];
char c[200005];
vector<pair<int, char > > q1, q2;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cin >> c[i];
        L += a[i];
    }
    int k = 0;
    for (int i = 1; i <= n; i ++){
        if (sum == 0 && k + a[i] > L / 2){
            if (L / 2 - k > 0) q1.push_back({(L / 2 - k), c[i]});
            if (k + a[i] - (L + 1) / 2 > 0) q2.push_back({k + a[i] - (L + 1) / 2, c[i]});
            sum = 1;
        }
        else if (sum == 0){
            k += a[i];
            q1.push_back({a[i], c[i]});
        }
        else {
            q2.push_back({a[i], c[i]});
        }
    }
    /*
    for (int i = 0; i < q1.size(); i ++){
        cout << q1[i].first << q1[i].second << " ";
    }
    cout << "| ";
    for (int i = 0; i < q2.size(); i ++){
        cout << q2[i].first << q2[i].second << " ";
    }*/
    int j = q2.size() - 1;
    for (int i = 0; i < q1.size(); i ++){
        int tl = q1[i].first;
        char sl= q1[i].second;
        while (tl){
            int tr = q2[j].first;
            char sr = q2[j].second;
            if (tl - tr < 0){
                if (sl != sr) ans += tl;
                tr -= tl;
                q2[j] = {tr, sr};
                break;
            }
            else {
                if (sl != sr) ans += tr;
                tl -= tr;
                j --;
            }
        }
    }
    cout << ans;

    return 0;
}
