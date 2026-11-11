#include<bits/stdc++.h>
#define ll long long
const int N = 5e5 + 5;
int n,m;
int a[N];
ll b[N];
int ans[N];
int r[N],l[N];
int ip;
bool flag = 1;
bool op = 1;
int maxnz = 1;
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(a[i] != i) op = 0;
    }
    if(op == 1){
        m *= 2;
        ll o = sqrt(m);
        for(int i = o;i >= 1;i--)
            if(i * (i + 1) <= m){
                cout << i + 1 << "\n";
                return 0;
        }
    }
    sort(a + 1, a + n + 1);
     for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= i - 1;j ++){
                int q = 0;
                ll ios = 0;
                bool qui = 0;
            for(int o = j;o <= i;o ++){
                ios += a[i] - a[o];
                q ++;
                if(ios > m){
                    q --;
                    maxnz = max(maxnz,q);
                    qui = 1;
                    break;
                    }
                    maxnz = max(maxnz,q);
                }
                if(qui == 1) break;
            }
        }
    cout << maxnz;
    return 0;
}
