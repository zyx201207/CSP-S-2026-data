#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  srand(time(NULL));
  cout << rand() % 100;
  for(int i = 1; i <= n; i++) {
    system("cd /home/noilinux/HN-S01047/T/ && ulimit -s 102400 && ./init");
    system("cd /home/noilinux/HN-S01047/T/ && ulimit -s 102400 && ./ans");
    system("cd /home/noilinux/HN-S01047/T/ && ulimit -s 102400 && ./T");
    if(system("cd /home/noilinux/HN-S01047/T/ && diff T.out T.ans -Bb")) return cout << "WA", 0;
    cout << "AC\n";
  }
  return 0;
}
/*
cd /home/noilinux/HN-S01047/T/ && ulimit -s 102400 && g++ check.cpp -o check && time ./check
*/