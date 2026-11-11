#include <bits/stdc++.h>
using namespace std;

int nums[200002][34];

int main(){
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);

    int n, m, f = 1;
    long long a, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a;
        int cnt = 30;
        while (a != 0){
            if (a % 2 == 0) nums[i][cnt] = 0;
            else nums[i][cnt] = 1;
            a /= 2;
            --cnt;
        }
        nums[i][31] = i-1;
        nums[i][32] = i+1;
    }

    for (int i = 1; i <= 30; ++i){
        ans *= 2;
        int cnt = 0, b = f;
        while (b != n+1){
            if (nums[b][i]) ++cnt;
            b = nums[b][32];
        }
        if (cnt >= m){
            ++ans;
            while (b != n+1){
                if (!nums[b][i]) {
                    if (b != f) nums[nums[b][31]][32] = nums[b][32];
                    else f = nums[b][32];
                    nums[nums[b][32]][31] = nums[b][31];
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
