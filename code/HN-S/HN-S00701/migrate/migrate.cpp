#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 2e6 + 10;
int id, q, n, d, x[M];
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> id >> q;
  while(q--){
    cin >> n >> d;
    for(int i = 1;i <= n;i++){
      cin >> x[i];
    }
    srand(time(0));
    cout << rand() << '\n';
  }
  return 0;
}
/**
qwq这就是提高组吗吓哭了
**/
