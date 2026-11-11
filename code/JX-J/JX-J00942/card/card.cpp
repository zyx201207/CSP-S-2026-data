#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int n, m;
int a[maxn];
int cnt[maxn];

void solve(int k){
    vector<int> now;
    for(int i = k; i <= n; i++){
        bool flag = false;
        int l = 0;
        for(int j = i; j <= n; j++){
            if(now[j] = a[i]){
                flag = true;
                l = j;
                break;
            }
        }

        if(!flag){
            now.push_back(a[i]);
        }else{
            for(int j = l + 1; j < now.size(); j++)
                now[j] = 0;
        }
    }

    for(auto x : now){
        cnt[x]++;
    }
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++){
        solve(i);
    }

    for(int i = 1; i <= m; i++)
        cout << cnt[i] << ' ';
    return 0;
}
