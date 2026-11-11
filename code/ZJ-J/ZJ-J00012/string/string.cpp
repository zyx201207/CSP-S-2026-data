#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
int n, a[MAXN];
long long divide, change;
char ch[MAXN];
string str;

long long gcd(long long a, long long b){
    if (a < b){
        swap(a, b);
    }
    if (!(a % b)){
        return b;
    }
    return gcd(a%b, b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> ch[i];
        if (i > 1){
            divide = gcd(divide, a[i]);
        } else {
            divide = a[i];
        }
    }
    for (int i = 1; i <= n; i++){
        a[i] /= divide;
        for (int j = 1; j <= a[i]; j++){
            str += ch[i];
        }
    }
    string rev;
    int sz = str.size();
    for (int i = 0; i < sz; i++){
        rev += str[sz-i-1];
    }
    int mid = (rev.size())/2+(str.size())%2;
    for (int i = 0; i < mid; i++){
        if (str[i] != rev[i]){
            change++;
        }
    }
    cout << change*divide;
}