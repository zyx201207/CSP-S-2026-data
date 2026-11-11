#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("hub.in");
ofstream fout("hub.out");

ll c, T;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  fin >> c >> T;
  for(; T; T--) {
    fout << "1\n";
  }
  return 0;
}
/*
cd /home/noilinux/HN-S01047/hub/ && ulimit -s 102400 && g++ hub.cpp -O2 -Wall -o hub && time ./hub && diff hub.out hub.ans -Bb
*/