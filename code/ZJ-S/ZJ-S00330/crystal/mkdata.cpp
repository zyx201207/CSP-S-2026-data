#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <tuple>

namespace tmp_rand {

auto tm = std::chrono::system_clock::now().time_since_epoch().count();
std::random_device rd;
std::seed_seq sd({static_cast<decltype(rd())>(tm), rd(), rd(), rd()});

} // namespace tmp_rand

int main() {
  std::ofstream in("crystal.in");
  std::mt19937_64 rng(tmp_rand::sd);
  std::uniform_int_distribution<long long> dis_a(-1e12, 1e12), dis_m(1, 1e18), dis_n(1, 5e3);
  long long n = dis_n(rng), m = dis_m(rng);
  std::vector<long long> a(n);
  in << n << ' ' << m << '\n';
  for (auto &x : a) {
    x = dis_a(rng);
    in << x << ' ';
  }
  in.put('\n');
  return 0;
}
