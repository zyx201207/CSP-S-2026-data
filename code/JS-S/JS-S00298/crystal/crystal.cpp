#include<bits/stdc++.h>
using namespace std;
#define let long long
#define var unsigned long long
const let fic = 1;
const int al = 5e5 + 10;

let a[al];
let df[al];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    int n;
    let m;
    cin >> n >> m;
    int maxn = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i ++)
        df[i] = df[i - 1] + a[i];
    int j = 1;
    for(int i = 1;i <= n;i ++){
        while(j < i && a[i] * (i - j + 1) - (df[i] - df[j - 1]) > m){
            //cout << i << ' ' << j << ' ' << a[i] * (i - j + 1) - (df[i] - df[j - 1]) << '\n';
            j ++;
        }
        //cout << i << ' ' << j << ' ' << a[i] * (i - j + 1) - (df[i] - df[j - 1]) << '\n';
        maxn = max(maxn , i - j + 1);
    }
    cout << maxn;
    return 0;
}
