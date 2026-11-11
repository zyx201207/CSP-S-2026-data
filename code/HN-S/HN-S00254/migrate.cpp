#include <bits/stdc++.h>
#define int ll
//#define DEBUG
using namespace std;
using ll = long long;

struct node {
  int tm, tp, l, r, v;
}eve[6000060];

struct p3 {
  int mn[3], cnt[3];

  p3 operator +(const p3 &b) const {
    int a[6] = {mn[0], mn[1], mn[2], b.mn[0], b.mn[1], b.mn[2]};
    sort(a, a + 6);
    unique(a, a + 6);
    for(int i = 1; i < 6; i++) a[i] = max(a[i], a[i - 1]);
    p3 res;
    for(int i = 0; i < 3; i++) {
      res.mn[i] = a[i], res.cnt[i] = 0;
      for(int j = 0; j < 3; j++) {
        if(mn[j] == a[i]) res.cnt[i] += cnt[j];
        if(b.mn[j] == a[i]) res.cnt[i] += b.cnt[j];
      }
    }
    return res;
  }
}d[8000080];

int _, n, dis, x[2000020], l[2000020], r[2000020], s1[2000020], s1x[2000020], p1x[2000020], t[2000020], ec;

p3 I() {
  p3 res;
  for(int i = 0; i < 3; i++) res.mn[i] = 10000000, res.cnt[i] = 0;
  return res;
}

void pushdn(int id) {
  for(int i = 0; i < 3; i++) d[id * 2].mn[i] += t[id], d[id * 2 + 1].mn[i] += t[id];
  t[id * 2] += t[id], t[id * 2 + 1] += t[id];
  t[id] = 0;
}
void build(int id = 1, int l = 1, int r = n) {
  d[id] = I(), t[id] = 0;
  if(l == r) {
    d[id].mn[0] = 0, d[id].cnt[0] = 1;
    return ;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  d[id] = d[id * 2] + d[id * 2 + 1];
}
void modify(int ml, int mr, int v, int id = 1, int l = 1, int r = n) {
  if(r < ml || mr < l) return ;
  if(ml <= l && r <= mr) {
    for(int i = 0; i < 3; i++) d[id].mn[i] += v;
    t[id] += v;
    return ;
  }
  pushdn(id);
  int mid = (l + r) >> 1;
  modify(ml, mr, v, id * 2, l, mid);
  modify(ml, mr, v, id * 2 + 1, mid + 1, r);
  d[id] = d[id * 2] + d[id * 2 + 1];
}
p3 query(int ql, int qr, int id = 1, int l = 1, int r = n) {
  if(r < ql || qr < l) return I();
  if(ql <= l && r <= qr) return d[id];
  pushdn(id);
  int mid = (l + r) >> 1;
  return query(ql, qr, id * 2, l, mid) + query(ql, qr, id * 2 + 1, mid + 1, r);
}
int gmax(int x, int id = 1, int l = 1, int r = n) {
  if(d[id].mn[0] != x && d[id].mn[1] != x && d[id].mn[2] != x) return 0;
  if(l == r) return l;
  pushdn(id);
  int mid = (l + r) >> 1;
  int tmp = gmax(x, id * 2 + 1, mid + 1, r);
  if(tmp) return tmp;
  else return gmax(x, id * 2, l, mid);
}

int gans() {
  build();
  int ans = 0;
  for(int i = 1; i <= ec; i++) {
    if(eve[i].tp == 1) {
      modify(eve[i].l, eve[i].r, eve[i].v);
    }else {
      //cout << eve[i].tm << ' ' << eve[i].l << ' ' << eve[i].r << '|';
      p3 tmp = query(eve[i].l, eve[i].r);
      int ts = 0;
      for(int i = 0; i < 3; i++) {
        //cout << tmp.mn[i] << ',' << tmp.cnt[i] << ' ';
        if(tmp.mn[i] == 2) ts += tmp.cnt[i];
      }
      //cout << gmax(2) << ' ' << s1x[gmax(2)] << ' ' << s1[gmax(2)] << ' ' << ts << '|';
      int tx = gmax(2);
      /*
      if(tx >= eve[i].l) {
        if(tx != eve[i].l) ts += s1[tx];
        else ts += s1x[tx];
      }
      //cout << tx << ' ' << ts << ' ' << p1x[eve[i].tm] << '\n';
      ans += ts * (p1x[eve[i].tm] + 1);
      //*/
      ans += ts;
    }
  }
  return ans;
}

void solve() {
  cin >> n >> dis;
  for(int i = 1; i <= n; i++) cin >> x[i];
  for(int i = 1; i <= n; i++) {
    l[i] = lower_bound(x + 1, x + n + 1, x[i] - dis) - x;
    r[i] = upper_bound(x + 1, x + n + 1, x[i] + dis) - x - 1;
  }
  for(int i = n - 1; i >= 1; i--) {
    s1x[i] = s1x[r[i]] + (r[i] - max(i, r[i - 1]));
    s1[i] = s1x[r[i]] + (r[i] - i);
  }
  l[n + 1] = n + 1;
  for(int i = 2; i <= n; i++) {
    p1x[i] = p1x[l[i]] + (min(i, l[i + 1]) - l[i]);
  }
  for(int i = 1; i <= n; i++) {
    eve[++ec] = {l[i], 1, i + 1, r[i], 1};
    eve[++ec] = {i, 1, i + 1, r[i], -1};
    eve[++ec] = {i, 2, r[i] + 1, n, 0};
  }
  sort(eve + 1, eve + ec + 1, [](node a, node b) {return a.tm == b.tm? a.tp < b.tp : a.tm < b.tm;});
  cout << gans() << '\n';
}

void clear() {
  ec = 0;
  for(int i = 1; i <= n; i++) l[i] = r[i] = s1[i] = s1x[i] = p1x[i] = 0;
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  for(cin >> _ >> _; _--; clear()) solve();
  return 0;
}
/*
My Luogu ID:928986
Oh well.
I wrote almost 20 rows of solution because it is hard but not-so hard. I have to do it carefully, so I recorded it here.
*/
