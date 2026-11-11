#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> ans;
int main(){

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    ans.resize(m, 0);
    string v[n];
    for(int i = 0; i < n; i++) v[i] = ' ';
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        if(i == 0) v[0] += x;
        else{
            auto p = v[i-1].find(x);
            if(p != -1) {
                v[i] = v[i-1].substr(0,p) += x;
            }
            else{
                v[i] = v[i-1] + x;
            }
        }
        for(char c : v[i]){
            int d = (int)c;
            ans[d]++;
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[m] << ' ';
    }
    return 0;
}
