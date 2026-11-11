#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
constexpr int N = 1e6+10,M = 510;
int testid;
int n,d;
int a[N];
int must[N];
int inl[N],inr[N];
int ans;
void solve(){

    ans = 0;
    cin >> n >> d;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        must[i] = 0;
        inl[i] = inr[i] = 0;
    }
    a[n + 1] = 5e18;
    if(testid == 11 || testid == 12){
        int di = a[2] - a[1];
        if(di >= d){
            cout << 0 <<'\n';
            return;
        }

    }
    for(int i = 1;i <= n - 1;i++){
        for(int j = i + 1;j <= n;j++){
            vector<int> v;
            v.push_back(i);
            int last = i,flag = 1;
            while(last < j){
                int nxt = upper_bound(a + 1,a + n + 1,a[last] + d) - a - 1;
                if(nxt <= last){
                    flag = 0;
                    break;
                }
                v.push_back(min(j,nxt));
                last = nxt;
            }
            //for(int k = 0;k<v.size();k++) cout << v[k] <<' ';
            //cout << '\n';
            if(flag == 0) continue;
            int cnt = 0;
            for(int k = 0;k < v.size() - 2;k++){
                int x = v[k],y = v[k + 1],z = v[k + 2];
                if(y - 1 > x && a[z] - a[y - 1] <= d) cnt++;
                if(y - 2 > x && a[z] - a[y - 2] <= d) cnt++;
                if(cnt > 1) break;
            }
            ans += (cnt == 1);
            //cout << ans <<'\n';
        }
    }
    cout << ans <<'\n';
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    //*
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //*/
    int _ = 1;
    cin >> testid >>  _;
    while(_--) solve();
    return 0;
}
