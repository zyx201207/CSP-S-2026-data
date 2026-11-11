#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, m, a[N], flag, nxt[N], pre[N], lst[N], cnt[N], num[N], t[N], b[N], rk[N];

bool cmp(int x, int y){
    return t[x] > t[y];
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i-1]) flag = 1;
    }
    for(int i = n; i >= 1; i--){
        nxt[i] = lst[a[i]], num[a[i]]++;
        if(nxt[i] == 0) t[a[i]] = i;
        else pre[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
    if(!flag){
        for(int i = 1; i <= n; i++){
            if(a[i] != a[i-1]) cout << t[a[i]] << " ";
        }
        cout << endl;
    } else if(n*m <= 6e8){
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; ){
                cnt[a[j]]++;
                j = t[a[j]]+1;
            }
        }
        for(int i = 1; i <= m; i++){
            cout << cnt[i] << " ";
        }
        cout << endl;
    } else{
        int mn = n;
        for(int i = 1; i <= m; i++) mn = min(t[a[i]], mn);
        for(int i = 1; i <= m; i++) b[i] = i;
        sort(b+1, b+m+1, cmp);
        for(int i = 1; i <= m; i++){
            rk[b[i]] = i;
        }
        for(int i = 1; i <= m; i++){
            cnt[b[i]] = num[b[i]];
            int mx = t[b[i]];
            for(int j = t[b[i]]+1; j <= n; j++){
                if(t[a[j]] > mx) cnt[a[j]] += num[b[i]];
            }
        }
        for(int i = 1; i <= m; i++)cout << cnt[i] << " ";
        cout << endl;
    }
    return 0;
}
