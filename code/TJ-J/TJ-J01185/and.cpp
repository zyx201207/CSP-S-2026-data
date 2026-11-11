// 25pts
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N = 2e5 + 10;
int a[N];

signed main(){

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int full = (1 << n) - 1;
    int mx = -((1 << 21) - 10);
    for (int state = 0;state <= full;state++){
        int cnt = 0;
        int sum = -1;
        for (int i = 1;i <= n;i++){
            if (state & (1 << (i - 1))){
                cnt++;
                if (sum == -1){
                    sum = a[i];
                } else {
                    sum &= a[i];
                }
            }
        }
        if (cnt != m) continue;
        mx = max(mx, sum);
    }
    cout << mx;

    return 0;
}

