#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
ll l, ans;
int n;
int a[N];
char c[N];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        l += a[i];
    }

    int i = 1, j = n, cnt1 = 1, cnt2 = 1;
    while(i < j){
        cnt1 = a[i] - cnt1 + 1;
        cnt2 = a[j] - cnt2 + 1;

        if(c[i] != c[j]){
            ans += min(cnt1, cnt2);
        }

        if(cnt1 == cnt2){
            i++, j--;
            cnt1 = 1, cnt2 = 1;
        } else if(cnt1 > cnt2){
            cnt1 -= cnt2;
            j--, cnt2 = 1, cnt1 = a[i] - cnt1 + 1;
        } else {
            cnt2 -= cnt1;
            i++, cnt1 = 1, cnt2 = a[j] - cnt2 + 1;
        }
    }

    cout << ans;

    return 0;
}
