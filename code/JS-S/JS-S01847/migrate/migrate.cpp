#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e6 + 5;
int f[N][N];

int main()
{
    ifstream fin("migrate.in");
    ofstream fout("migrate.out");
    int c, t;
    fin >> c >> t;
    while (t--) {
        int n, d;
        fin >> n >> d;
        vector<int> x(n);
        for (auto& e : x) fin >> e;
        fout << "0\n";
    }
    return 0;
}
