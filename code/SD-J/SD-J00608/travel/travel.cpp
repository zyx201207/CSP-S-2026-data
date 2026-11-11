#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned
#define topQ priority_queue
#define bint __int128

inline int in() {
 int x = 0; bool f = false; char ch = getchar();
 while (!isdigit(ch)) f |= ch == '-', ch = getchar();
 while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
 return f ? -x : x;
}

constexpr int Mod = 998244353, N = 1e5 + 1e3;

char s1[N], s2[N], s3[N], s4[N];

signed main() { freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
 scanf("%s%s%s%s", s1 + 1, s2 + 1, s3 + 1, s4 + 1);
 int p1 = (s1[1] - '0') * 10 + s1[2] - '0', p2 = (s3[1] - '0') * 10 + s3[2] - '0';
 if (p1 == p2) {
  int pp1 = (s2[1] - '0') * 10 + s2[2] - '0', pp2 = (s4[1] - '0') * 10 + s4[2] - '0';
  if (pp1 == pp2) {
   int tk1 = s2[3] >= 'A' && s2[3] <= 'C', tk2 = s4[3] >= 'A' && s4[3] <= 'C';
   if (tk1 == tk2) {
    if (abs(s2[3] - s4[3]) == 1) {
     puts("1111");
    } else {
     puts("1110");
    }
   } else {
    puts("1100");
   }
  } else {
   puts("1000");
  }
 } else {
  puts("0000");
 }
 return 0;
}
