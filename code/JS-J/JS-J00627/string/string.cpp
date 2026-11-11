#include <bits/stdc++.h>
using namespace std;
string c = "";
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int x = 0;
    for (int i = 1;i <= n;i++){
        long long m;
        char a;
        cin >> m >> a;
        for (long long j = 1;j <= m;j++) c += a;
        x += m;
    }
    long long v = 0;
    for (long long i = 0;i < x / 2;i++){
        if (c[i] != c[x - i - 1]) v++;
        //cout << i << " " << x - i - 1 << endl;
    }
    cout << v;
}

