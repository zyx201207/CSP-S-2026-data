#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], ans = 1;
void dfs(string s, int i){
    if(i == n){
        int cnt = 0, first0;
        for(int i = n - 1; i >= 0; i--)
            if(s[i] - '0')
                cnt++, first0 = i;
        if(cnt == m){
            int ans6 = a[1 + first0];
            for(int i = 0; i < n; i++)
                if(s[i] - '0')
                    ans6 &= a[i + 1];
            ans = max(ans, ans6);
        }
        return;
    }
    dfs(s + '1', i + 1);
    dfs(s + '0', i + 1);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool ok1617 = 1;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] >= 4)
            ok1617 = 0;
        if(a[i] == 0)
            cnt0++;
        if(a[i] == 1)
            cnt1++;
        if(a[i] == 2)
            cnt2++;
        if(a[i] == 3)
            cnt3++;
    }
    if(n <= 20){
        dfs("", 0);
        cout << ans;
        return 0;
    }
    if(m == 1){
        for(int i = 1; i <= n; i++)
            ans = max(ans, a[i]);
        cout << ans;
        return 0;
    }
    if(m == n){
        for(int i = 1; i <= n; i++)
            ans &= a[i];
        cout << ans;
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != j)
                    ans = max(ans, a[i] & a[j]);
        cout << ans;
        return 0;
    }
    if(m == n - 1){
        for(int i = 1; i <= n; i++)
            ans &= a[i];
        cout << ans;
        return 0;
    }
    if(ok1617){
        if(cnt3 >= m)
            cout << 3;
        else if(cnt2 + cnt3 >= m)
            cout << 2;
        else if(cnt1 + cnt2 + cnt3 >= m)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    cout << 0;
    return 0;
}
