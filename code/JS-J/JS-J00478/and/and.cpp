#include<bits/stdc++.h>
using namespace std;

vector<int> q;
int n, m, ans = 0;
int a[200010];

void pd(){
    int reans = q[0];
    for(int i = 1;i < q.size();i++){
        reans = reans & q[i];
    }
    ans = max(ans, reans);
}
void C(int dep, int cnt){
    if(dep > n){
        if(cnt == m) pd();
        return;
    }
    if(cnt == m){
        pd();
        return;
    }
    if(n - dep + cnt + 1 < m) return;
    C(dep + 1, cnt);
    q.push_back(a[dep]);
    C(dep + 1, cnt + 1);
    q.pop_back();
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    if(m == 1){
        for(int i = 1;i <= n;i++){
            ans = max(ans, a[i]);
        }
        cout << ans;
        return 0;
    }
    C(1, 0);
    cout << ans;
    return 0;
}