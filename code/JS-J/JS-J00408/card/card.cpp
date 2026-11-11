#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
const int N = 500010;
int a[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++) if(a[j] == i) sum++;
        cout << sum << " ";
    }
}
