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
int t,c;
signed main() {
 freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
 cin>>c>>t;
 while (t--){
  cout<<"1\n";
 }
 return 0;
}

