#include <bits/stdc++.h>
using namespace std;

long long a[200005];
long long e[200005];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    long long b = 0;
    for(int i = n - 1;i > n - m;i--){
        b += b * pow(2,i);
        e[i] = 1;
    }
    int maxn = -1;
    int d;
    int c = b;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - m;j++){
            if(c % 2 != 0){
                e[j] = 1;
            }
            else {
                e[j] = 0;
            }
            c /= 2;
        }
    }
}
