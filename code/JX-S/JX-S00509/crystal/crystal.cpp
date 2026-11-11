
// Welcome to watch my bad code and sentences, My name is Chan.
// Yes, I was join the CSP-J and CSP-S.
// Maybe no one knowed me.
// Why did I used English to write this passage?
// I didn't know how to change the input method in Chinese.
// I said that in CSP-J.

// Oh my god, this problem was so difficult for me.
// I had no confidence to finish this program.
// I spent more than 3 hours to finish it.
// But now, I gave up and wrote my feelings.

// Could you understand how happy when I saw my code run simply.
// Three examples were Ok, but the last one I didn't know what error I made.
// I had to stopped.
// Bye.
// 6:23 p.m. Oct. 31
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
int n, m, ans;
long long a[N], c[N], pos;
int Find(int pos, long long num);
long long tree[N];
void add(int pos, long long a);
long long found(int a);
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld ", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        c[i] = a[i] - a[i - 1];
        add(i, c[i] * (i - 1));
        //printf("a[%d] = %lld\n", i, a[i]);
    }
    //("\n\n%lld\n\n", found(n));
    for (int i = 1; i <= n; i++) {
        pos = Find(i, m);
        if (pos - i + 1 >= ans) {
            ans = pos - i + 1;
        }
        add(i, c[i] * (1 - i));
    }
    printf("%lld\n", ans);

    return 0;
}

int Find(int pos, long long num) {
    int l = pos, r = n;
    int mid = (l + r) / 2;
    while (l < r) {
        mid = (l + r) / 2;
        if (found(mid) > num)
            r = mid - 1;
        else
            l = mid;
        if (r - l == 1)
            break;
    }
    if (found(r) <= num)
        return r;
    if (found(l) <= num)
        return l;
    return -1;
}
void add(int pos, long long a) {
    for (int i = pos; i <= n; i += (i & (1 + ~i)))
        tree[i] += a;
}
long long found(int a) {
    long long ans = 0;
    for (; a; a -= a & (1 + ~a))
        ans += tree[a];
    return ans;
}

