#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 4e18;
const int N = 2e6 + 10;
int n,a[N],d,R[N],pre[N],suf[N],q[N],c,b[N],tot;
vector<int> has[N];
inline void init(){
    for(int i=1;i<=n;i++){
        pre[i] = suf[i] = 0;
        has[i].clear();
    }
    int r=n;
    for(int l=n;l>=1;l--){
        while(a[r]-a[l]>d)r--;
        R[l] = r;
        has[r].push_back(l);
    }
    for (int i = 1; i <= n;i++){
        int len = has[i].size();
        for (int j = 0; j < len;j++){
            if(j==len-1)
                pre[i] += pre[has[i][j]]+1;
            else
                pre[i]++;
        }
    }
    for (int i = n; i >= 1;i--){
        for(int j=max(i+1,R[i-1]+1);j<=R[i];j++){
            if(j==R[i])
                suf[i] += suf[j]+ 1;
            else
                suf[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        int nxt = R[i];
        if(nxt==i+1||nxt==i)continue;//不可能有两条最短路
        int nr = R[nxt - 1];
        int st = R[nxt - 2] + 1;
        for (int j = st; j <= nr;j++){
            if(j==R[nxt]){
                ans = ans + (pre[i] + 1) * (suf[j] + 1);
            }else
                ans = ans + pre[i] + 1;
        }
    }
    cout << ans << '\n';
}
inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(c<=6){
        int r=n;
        for(int l=n;l>=1;l--){
            while(a[r]-a[l]>d)r--;
            R[l] = r;
        }
        int ans = 0;
        for(int st=1;st<=n;st++){
            tot = 0;
            for (int en = st + 1; en <= n;en++){
                if(R[en-1]==en-1)break;
                int now = st;
                tot = 0;
                b[++tot] = now;
                while(now<en){
                    now = R[now];
                    b[++tot] = now;
                }
                b[tot] = min(b[tot], en);
                int cnt = 1;
                bool f = 1;
                if(tot<=2)
                    f = 0;
                for(int j=3;j<=tot;j++){
                    if(b[j-1]-1>b[j-2]){
                        if(a[b[j]]-a[b[j-1]-1]<=d){
                            if(b[j-1]-2>b[j-2]&&a[b[j]]-a[b[j-1]-2]<=d)
                                continue;
                            cnt++;
                        }
                            
                    }
                }
                if(cnt==2){
                    ans++;
                }
                    
            }
        }
        cout << ans << '\n';
    }else{
        init();
    }
    
}
signed main(){
     freopen("migrate.in", "r", stdin);
     freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> c >> t;
    while(t--)solve();
    return 0;
}
/*
r[i]表示i尽力往右跳最右边能跳到哪里
mn[i]表示i是从最左边哪里尽力跳过来的结果
pre[i]表示i前面的最长合法的长度
suf表示i后面最长合法的长度

6 3
0 1 2 3 4 7
*/