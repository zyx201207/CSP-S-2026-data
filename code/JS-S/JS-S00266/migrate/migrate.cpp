#include <bits/stdc++.h>
#define int long long
#define gc getchar
const int N = 2e6 + 10;

using namespace std;
namespace Sol{

int rd(){
    char c = gc(); int re = 0, fl = 1;
    while(c < '0' || c > '9'){
        if(c == '-') fl = -1; c = gc();
    }
    while(c >= '0' && c <= '9')
        re = re * 10 + c - '0', c = gc();
    return re * fl;
}

int a[N];

void main(){
    #ifdef LOCAL
    freopen("migrate4.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    #else
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C = rd(), T = rd();
    for(int n, d, mnt; T; T--){
        n = rd(), d = rd();
        for(int i=1; i<=n; i++) a[i] = rd();
        if(n <= 3){cout << "0\n"; continue;}
        mnt = a[2] - a[1];
        for(int i=2; i<n; i++) mnt = min(mnt, a[i+1]-a[i]);
        if(d <= mnt){cout << "0\n"; continue;}
        // if(C == 11 || C == 12){
            if(d >= 2*mnt && n >= d/mnt*2) 
                cout << n-d/mnt*2 + 1;
            else cout << 0;
            cout << '\n'; continue;
        // }

    }
}

}signed main(){Sol::main();}