#include <iostream>
using namespace std;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cout << 1 << ' ';
    }
    fclose(stdin);
    fclose(stdout);
}
