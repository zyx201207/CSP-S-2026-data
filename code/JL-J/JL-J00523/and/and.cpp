#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 1e5 + 5;
int n,m;
int a[N];
int sp = 0;

int dfs(int pos,int now,int cnt){
    if(pos > n){
        if(cnt == m){
            return now;
        }
        return 0;
    }
    if(cnt == m){
        return now;
    }
    return max(dfs(pos + 1,now,cnt),dfs(pos + 1,now & a[pos],cnt + 1));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(sp != 0){
            sp = sp & a[i];
        }else{
            sp = a[i];
        }
    }
    if(n == m){
        cout << sp;
        return 0;
    }
    if(m == 1){
        int maxn = INT_MIN;
        for(int i = 1;i <= n;i++){
            maxn = max(maxn,a[i]);
        }
        cout << maxn;
        return 0;
    }
    if(n <= 2000){
        if(m == 2){
            int ans = INT_MIN;
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(i != j){
                        ans = max(ans,a[i] & a[j]);
                    }
                }
            }
            cout << ans;
        }else{
            cout << dfs(1,1,0);
        }
    }else if(m == n - 1){
        int ans = INT_MIN;
        for(int i = 1;i <= n;i++){
            int tmp = 1;
            for(int j = 1;j <= n;j++){
                if(j != i){
                    tmp = tmp & a[j];
                }
            }
            ans = max(ans,tmp);
        }
        cout << ans;
    }else{
        sort(a + 1,a + n + 1,greater<int>());
        int ans = 1;
        for(int i = 1;i <= m;i++){
            ans = ans & a[i];
        }
        cout << ans;
    }

    return 0;
}
