#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
char c[N];
int n;
string add(string a, string b);
string the_ans = "0";
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int num = min(a[l], a[r]);
        if (c[l] != c[r])
            the_ans = add(the_ans, to_string(num));
        if (a[l] < a[r])
            a[r] -= num, l++;
        else if (a[r] < a[l])
            a[l] -= num, r--;
        else if (a[l] == a[r])
            l++, r--;
    }
    cout << the_ans << endl;
    return 0;
}

string add(string a, string b) {
    int num1[a.size() + 10] = {a.size()};
    int num2[b.size() + 10] = {b.size()};
    int ans[max(num1[0], num2[0]) + 10] = {max(num1[0], num2[0])};

    for (int i = 1; i <= num1[0]; i++)
        num1[i] = a[num1[0] - i] - '0';
    for (int i = 1; i <= num2[0]; i++)
        num2[i] = b[num2[0] - i] - '0';

    for (int i = 1; i <= max(num1[0], num2[0]); i++) {
        ans[i] += num1[i] + num2[i];
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    if (ans[ans[0] + 1])
        ans[0]++;

    string answer = "";
    for (int i = ans[0]; i >= 1; i--)
        answer = answer + char(ans[i] + '0');

    return answer;
}
