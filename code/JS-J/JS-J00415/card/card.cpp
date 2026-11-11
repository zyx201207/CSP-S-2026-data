#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 5e5 + 10;
int a[N];
int b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n>>m;
    for (int i = 1;i <= n;i++){
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1;i <= n;i++){
        b[i] = b[i-1] + a[i];
    }
    for (int i = 1;i <= m;i++)
        cout << b[i] << ' ';
    return 0;
}
