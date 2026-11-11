#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], cnt[M];
bool have[M];
vector<int> rest;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(have[a[j]]){
                bool fnd = false;
                for(int k = 0; k < (int)rest.size(); k++){
                    if(rest[k] == a[j]){
                        for(int m = k; m < (int)rest.size(); m++){
                            rest.pop_back();
                        }
                        break;
                    }
                }
            }
            have[a[j]] = true;
            rest.push_back(a[j]);
        }
        for(int j = (int)rest.size() - 1; j >= 0; j++){
            cnt[rest[j]]++;
            if(!rest.empty()){
                rest.pop_back();
            }
        }
        fill(have + 1, have + m + 1, false);
    }
    for(int i = 1; i <= m; i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
