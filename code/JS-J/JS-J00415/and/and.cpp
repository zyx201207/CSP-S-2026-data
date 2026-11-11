#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5 + 10;
int a[N];
int b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int k = 1;
    for (int i = n;i >= 1;i--){
        b[k] = a[i];
        k++;
    }
    int s = a[n];
    for (int i = 2;i <= m;i++){
        s = s & b[i];
    }
    cout << s;
    return 0;
}
