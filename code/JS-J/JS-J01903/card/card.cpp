#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N],t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long ans[N];
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(a[j] != a[j - 1]) ans[a[j]]++;
        }
        a[i] = 0;
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
