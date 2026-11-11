#include<bits/stdc++.h>
using namespace std;
map <int, int> ab;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ab[x]++;
    }
    int cnt = 0;
    for(auto i : ab){
        cnt += i.second;
        cout << cnt << ' ';
    }
    return 0;
}
