#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll m, c[N], cnum[N], ans;
vector<ll>  b;
map<ll, int> mp;
// cin
inline int read_int() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline ll read_ll() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}

//tree
int lowbit(int x) {
  return x & -x;
}
void add(int x, ll y, int num) {

  for (; x <= n; x += lowbit(x)) {
    c[x] += y;
    cnum[x] += 1LL * num;
  }
  return ;
}
ll query1(int x) {
    ll sum = 0;
    for (; x; x -= lowbit(x)) sum += c[x];
    return sum;
}
ll query2(int x) {
    ll sum = 0;
    for (; x; x -= lowbit(x)) sum += cnum[x];
    return sum;
}
ll minn(ll a, ll b) {
    return (a <= b ? a : b);
}
// main
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  n = read_int(), m = read_ll();
  for (int i = 1; i <= n; i++) {
    ll a = read_ll();
    b.push_back(a);
    mp[a]++;
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int nn = b.size();
  b.insert(b.begin(), 0);
  for (int i = 1; i <= nn; i++) add(i, b[i] * 1LL * mp[b[i]], mp[b[i]]);
  for (int i = 1; i <= nn; i++) {
    int left = 1, right = i, l = 0;
    while (left <= right) {
        int mid = left + right >> 1;
        if (b[i] * (query2(i) - query2(mid - 1)) - (query1(i) - query1(mid - 1)) <= m) l = mid, right = mid - 1;
        else left = mid + 1;
    }
    ll sum = query2(i) - query2(l - 1), mm = m - (b[i] * (query2(i) - query2(l - 1)) - (query1(i) - query1(l - 1)));
    if (mm >= b[i] - b[l - 1]) sum += min(mm / (b[i] - b[l - 1]), 1LL *  mp[b[l - 1]]);
    ans = max(ans, sum);
  }
  write(ans);
  return 0;
}
