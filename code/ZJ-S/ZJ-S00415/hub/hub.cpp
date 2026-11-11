#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    c++;
    mt19937_64 m(time(0));
    for(int i = 1; i <= t; i++){
        cout << m() % c << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}