#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N];
int ans[M], num[M];
int lst[M];
bool ok[M];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bool isA = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        lst[a[i]] = -1;
        num[a[i]]++;
        isA &= (a[i] >= a[i - 1]);
    }
    if(!isA){
        for(int i = n; i >= 1; i--){
            if(lst[a[i]] != -1) continue;
            lst[a[i]] = i;
            for(int j = 1; j <= m; j++) ok[j] = false;
            for(int j = i; j <= n;){
                ok[a[j]] = true;
                if(lst[a[j]] != -1 && j != lst[a[j]]) j = lst[a[j]];
                else j++;
            }
            for(int j = 1; j <= m; j++){
                if(ok[j]) ans[j] += num[a[i]];
            }
        }
        for(int i = 1; i <= m; i++){
            cout << ans[i] << ' ';
        }
    }else{
        for(int i = 1; i <= m; i++){
            num[i] += num[i - 1];
            cout << num[i] << ' ';
        }
    }

    return 0;
}

