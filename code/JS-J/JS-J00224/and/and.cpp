#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
int n,m;
ll tot = 0,mx = 0;
ll a[N];
ll s[N][32];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
        if(i == 1)tot = a[i];
        else tot &= a[i];
    }
    if(m == n){
        cout << tot;
        return 0;
    }
    if(m == 1){
        cout << mx;
        return 0;
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        ll x = a[i];
        for(int j = 0;j < 32;j++){
            if(x & (1 << j)){
                s[i][j] = 1;
            }else{
                s[i][j] = 0;
            }
        }
    }


    /*for(int i = 1;i <= n;i++){
        for(int j = 31;j >= 0;j--){
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }*/
    ll ans = 0;
    for(int i = 31;i >= 0;i--){
        ll cnt = 0,num = 0;
        vector<int> sz;
        for(int j = 1;j <= n;j++){
            if(s[j][i] == 1){
                cnt++;
                if(cnt == 1)num = a[j];
                else num &= a[j];
                sz.push_back(j);
            }
        }
        //for(int x : sz)cout << x << " ";
        //cout << "\n";
        if(cnt >= m){
            if(cnt == m){
                cout << num;
                return 0;
            }
            for(int j = i;j >= 0;j--){
                ll cnt1 = 0,numm = 0;
                for(int ii = 0;ii < sz.size();ii++){
                    if(s[sz[ii]][j]){
                        cnt1++;
                        if(cnt1 == 1)numm = a[sz[ii]];
                        else numm &= a[sz[ii]];
                    }
                }
                if(cnt1 == m){
                    cout << numm;
                    return 0;
                }
            }
            sort(sz.begin(),sz.end());
            ll ou = a[sz[0]];
            for(int ii = 1;ii < m;ii++){
                ou &= a[sz[ii]];
            }
            cout << ou;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
