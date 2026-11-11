// 11:36 3/6 24pts
// I can't finish $O(n^2)$ or $O(n)$ QAQ.
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
int n, m;
int a[5010];
int w[5010], ans[5010];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    for(int i = 1; i <= n; i++){
        vector<int> v;
        int ck = 0;
        for(int j = i; j <= n; j++){
            int now = a[j];
            for(int k = 0; k < v.size(); k++){
                if(v[k] == now)
                    ck = 1;
            }
            if(ck){
                while(v.back() != now)
                    v.pop_back();
                v.pop_back();
            }
            v.push_back(now);
            ck = 0;
        }
        memset(w, 0, sizeof w);
        for(int j = 0; j < v.size(); j++)
            w[v[j]] = 1;
        for(int i = 1; i <= m; i++)
            ans[i] += w[i];
    }
    
    for(int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
}