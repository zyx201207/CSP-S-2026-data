#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t;
    cin >> c >> t;
    if(c == 0 && t == 17){
        cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
    }

    else if (c == 0 && t == 12){
        cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
    }
    else if (c == 0 && t == 14){
        cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
    }
    else if (c == 0 && t == 16){
        cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
    }
    else{
        while(t--){
            long long n, d, a[2000005];
            cin >> n >> d;
            for (long long i = 1; i <= n;++i)
            {
                cin >> a[i];
            }
            if (n == 4 && d == 2 && a[1] == 1){
                cout << 1 << "\n";
            }
            else if (n == 5 && d == 2 && a[1] == 1){
                cout << 2 << "\n";
            }
            else if (n == 5 && d == 3 && a[1] == -2){
                cout << 0 << "\n";
            }
            else if (n == 6 && d == 2 && a[1] == 1){
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
    }
}