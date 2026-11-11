#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6 + 5;
int c, t;
long long n, d;
long long a[N];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scnaf("%d %d", &c, &t);
    while(t --){
        scanf("%d %d", &n, &d);
        for(int i = 1;i <= n;i ++){
            scanf("%d", &a[i]);
        }
    }
    return 0;
}
