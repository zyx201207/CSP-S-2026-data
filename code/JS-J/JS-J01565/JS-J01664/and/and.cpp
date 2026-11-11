#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n, m;
bool a[N][50];
int sum[50];
vector<ll> g;
vector<ll> v;
bool anas[50];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    ll num;
    int cnt;
    int x;
    int maxx = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &num);
        g.push_back(i);
        cnt=0;
        while(num){
            cnt++;
            x = num%2;
            a[i][cnt] = x;
            if(x){
                sum[cnt]++;
                if(sum[cnt] >= m){
                    maxx = max(maxx, cnt);
                }
            }
            num/=2;
        }
        //for(int j = 1;j <= 40;j++) cout << a[i][j];
        //cout << endl;
    }
    //cout << "sum: " << endl;
    //for(int j = 1;j <= 40;j++) cout << sum[j];
    //cout << endl << maxx << endl;
    num = maxx;
    while(num){
        v.clear();
        for(int i = 0;i < g.size();i++){
            if(a[g[i]][num]) v.push_back(g[i]);
        }
        if(v.size() >= m){
            anas[num] = true;
            g = v;
        }
        v.clear();
        num--;
    }
    //for(int j = 1;j <= 40;j++) cout << anas[j];
    //cout << endl;
    ll ans(0);
    for(int j = 40;j >= 1;j--){
        ans = ans*2+anas[j];
    }
    cout << ans;
    return 0;
}
