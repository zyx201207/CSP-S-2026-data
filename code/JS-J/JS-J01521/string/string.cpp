#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long a[200005];
char c[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    unsigned long long sum = 0;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    int i = 1,j = n;
    unsigned long long s1 = a[1],s2 = a[n],l1 = 0,l2 = 0,res = 0;
    while(i < j) {
        //cout << i << ' ' << j << endl;
        if(c[i] != c[j])res += (min(s1,s2) - max(l1,l2));
        if(s1 > s2) {
            j --;
            l2 = s2;
            s2 += a[j];
        } else if (s1 < s2) {
            i ++;
            l1 = s1;
            s1 += a[i];
        } else {
            j --;
            l2 = s2;
            s2 += a[j];
            i ++;
            l1 = s1;
            s1 += a[i];
        }
    }
    cout << res;
    return 0;
}

/*
3
1 a
1 c
1 b
*/
