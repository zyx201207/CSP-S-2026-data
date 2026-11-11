#include<bits/stdc++.h>
using namespace std;

long long m, n;
int a[500005], c[500005];

int check(int s,int x) {
    int len = 1;
    for(int i = 1;i <= n;i ++) {
        if(a[i] > s) {
            continue;
        }

        c[len] = s - a[i];
        len ++;
    }
    sort(c + 1,c + len);
    int ans = 0;
    for(int i = 1;i <= len - 1;i ++) {
        if(x - c[i] < 0) {
            break;
        }
        ans ++;
        x -= c[i];
    }

    return ans;
}


int main() {

    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }

    int mx = -1;
    for(int i = 1;i <= 5e5;i ++) {
        mx = max(mx, check(i, m));
    }

    cout << mx;

    return 0;
}
