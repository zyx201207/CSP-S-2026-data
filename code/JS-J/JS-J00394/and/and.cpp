#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
int a[N],n,m;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = a[1];
    for (int i = 2;i <= n;i++){
        ans &= a[i];
    }
    sort(a + 1,a + 1 + n,cmp);
    if (m == 1){
        cout << a[1] << endl;
    }else if (m == n){
        cout << ans << endl;
    }else if (m == 2){
        int maxn = 0;
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                maxn = max(maxn,a[i] & a[j]);
            }
        }
        cout << maxn << endl;
    }else if (n <= 20){
        int x = a[1];
        for (int i = 2;i <= m;i++){
            x &= a[i];
        }
        cout << x << endl;
    }
    return 0;
}
