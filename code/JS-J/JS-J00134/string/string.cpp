#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n;
string s1;
struct node {
    int v;
    char s;
}a[MAXN];
int main() {
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    scanf("%d" , &n);
    s1 += ' ';
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].v >> a[i].s;
        for (int j = 1 ; j <= a[i].v ; j++) {
            s1 += a[i].s;
        }
    }
    int len = s1.size() - 1;
    string s2 , s3;
    for (int i = 1 ; i <= len / 2 ; i++) {
        s2 += s1[i];
    }
    if (len % 2 == 0) {
        for (int i = len ; i >= len / 2 + 1 ; i--) {
            s3 += s1[i];
        }
    } else {
        for (int i = len ; i >= len / 2 + 2 ; i--) {
            s3 += s1[i];
        }
    }
    int ans = 0;
    for (int i = 0 ; i < s2.size() ; i++) {
        if (s2[i] != s3[i]) ans++;
    }
    printf("%d" , ans);
    return 0;
}
