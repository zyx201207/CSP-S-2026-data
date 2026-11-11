#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m;
vector<int> v;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int res = 0;
    for(int i = 30; i >= 0; i--){
        vector<int> tmp;
        for(auto t : v){
            if(t >> i & 1) tmp.push_back(t);
        }
        if(tmp.size() >= m){
            res += 1 << i;
            v = tmp;
        }
    }
    cout << res;
    return 0;
}
