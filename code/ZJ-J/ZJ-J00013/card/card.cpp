#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, a[500005], cnt[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    vector<int> v;
    for(int k = 1;k <= n;k++){
        for(int i = k;i <= n;i++){
            for(int j = 0;j < v.size();j++){
                if(v[j] == a[i]){
                    for(j = v.size() - 1;j >= 0;j--){
                        if(v[j] == a[i]){
                            v.pop_back();
                            break;
                        }
                        v.pop_back();
                    }
                    break;
                }
            }
            v.push_back(a[i]);
        }
        while(!v.empty()){
            cnt[v[v.size() - 1]]++;
            v.pop_back();
        }
    }
    for(int i = 1;i <= m;i++)
        cout << cnt[i] << ' ';
    return 0;
}
