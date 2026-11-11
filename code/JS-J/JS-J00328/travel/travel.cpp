#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;


int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string c1, s1, c2, s2;
  std::cin >> c1 >> s1 >> c2 >> s2;
  int a1 = std::stoi(c1), a2 = std::stoi(c2);
  if (a1 == a2) std::cout << "1";
  else {
    std::cout << "0000";
    return 0;
  }
  int b1 = 0, b2 = 0;
  char d1, d2;
  for (int i = 0; i <= 2; i ++) {
    if (s1[i] >= '0' && s1[i] <= '9')  b1 = b1 * 10 + (s1[i] - '0');
    else d1 = s1[i];
    if (s2[i] >= '0' && s2[i] <= '9')  b2 = b2 * 10 + (s2[i] - '0');
    else d2 = s2[i];
  }
  if (b1 == b2) std::cout << "1";
  else {
    std::cout << "000";
    return 0;
  }
  if (((d1 >= 'A' && d1 <= 'C') && 
      (d2 >= 'A' && d2 <= 'C')) ||
      ((d1 >= 'D' && d1 <= 'F') && 
      (d2 >= 'D' && d2 <= 'F'))) {
    std::cout << '1';
  }
  else {
    std::cout << "00";
    return 0;
  }

  if (std::abs((d1 - 'A') - (d2 - 'A')) == 1) std::cout << '1';
  else std::cout << '0';
  return 0;
}