#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
struct sum{
    string s;
    long long num;
};
string r;
long long n, m = 0, x, ans = 0, f = 1, a = 1, b = 1;
sum num1[N], num2[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> r;
        num1[i].s = r;
        num1[i].num = x;
        num2[n - i + 1].s = r;
        num2[n - i + 1].num = x;
        m += x;
    }
    if (m % 2 == 0) {
        m = m / 2;
    }
    else {
        m = m / 2 + 1;
    }
    while(f <= m) {
        if (num1[a].s == num2[b].s){
            if(num1[a].num >= num2[b].num) {
                num1[a].num = num1[a].num - num2[b].num;
                f += num2[b].num;
                num2[b].num = 0;
                b++;
            }
            else{
                num2[b].num = num2[b].num - num1[a].num;
                f += num1[a].num;
                num1[a].num = 0;
                a++;
            }
        }
        else {
            if(num1[a].num >= num2[b].num) {
                num1[a].num = num1[a].num - num2[b].num;
                ans += num2[b].num;
                f += num2[b].num;
                num2[b].num = 0;
                b++;
            }
            else{
                num2[b].num = num2[b].num - num1[a].num;
                ans += num1[a].num;
                f += num1[a].num;
                num1[a].num = 0;
                a++;
            }
        }
    }
    cout << ans;

    return 0;
}
