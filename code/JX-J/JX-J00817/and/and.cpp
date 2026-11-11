#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], p[35], b[N], k;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m, p[1] = 1;
    for(int i = 2; i <= n; i++)p[i] = p[i - 1] * 2;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i < 30; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] >= p[i])cnt++;
        }
        if(cnt >= m){
            for(int j = 1; j <= n; j++){
                if(a[j] >= p[i])b[++k] = a[j];
            }
            sort(b + 1, b + k + 1, cmp);
            cout << b[m];
            return 0;
        }else{
            for(int j = 1; j <= n; j++){
                if(a[j] >= p[i])a[j] -= p[i];
            }
        }
    }
}
