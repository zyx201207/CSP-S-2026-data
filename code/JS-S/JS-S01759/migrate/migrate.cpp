#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, d, ans;
ll x[3000000];
ll xx[3000000];
ll cnt[3000000];

bool judge(){
    ll dif = x[2] - x[1];
    for(int i = 3; i <= n; i++){
        if(x[i]-x[i-1] != dif){
            return false;
        }
    }
    ll f = d / dif;
    if(f<2){
        ans = 0;
        return true;
    }
    ans = max(n-2*f+1,ll(0));
    return true;
}

void solve(){
    ans = 0;
    if(judge()){
        return;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= n; c++){
            xx[c] = 0;
            cnt[c] = 1;
        }
        q.push(i);
        xx[i] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int l=1, r=n;
            for(;x[l]<x[u]-d;l++);
            for(;x[r]>x[u]+d;r--);
            for(int j = l; j <= r; j++){
                if(xx[j]==xx[u]+1){
                    cnt[j]++;
                    continue;
                }
                if(xx[j] == 0){
                    xx[j] = xx[u]+1;
                    q.push(j);
                }
            }
        }
        //cout << i << endl;
        for(int c = 1; c <= n; c++){
            //cout << c << ":" << cnt[c] << endl;
            if(cnt[c]==2) ans++;
        }
    }
    ans /= 2;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        solve();
        cout << ans << endl;
    }
    return 0;
}

