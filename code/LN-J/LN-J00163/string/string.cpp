#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum,m,n;
    long long pos = 0;
    char c;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> sum >> c;
        for (int j = 0;j < sum;j++){
            s[pos++] = c;
        }
        m += sum;
    }
    long long op = 0;
    for (long long i = 0; i < floor(m / 2);i++){
        if (s[i] != s[m-i-1]) op++;
    }
    cout << op;
    return 0;
}
