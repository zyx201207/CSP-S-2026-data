#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
using LL = long long;

int a[32][N];
int b[N], idx[32], idxn;
int n, m;

void f(int t){
    if(t > 30){
        LL sum = (1<<30)-1;
        for(int i = 1; i <= idxn; i ++){
            sum = sum & b[i];
        }
        cout << sum << '\n';
        return;
    }
    memset(a, 0, sizeof(a));
    memset(idx, 0, sizeof(idx));
    for(int i = 1; i <= idxn; i ++){
        for(int j = 0; j < 30-t+1; j ++){
            if( (b[i]>>j)&1 )a[j][++idx[j]] = b[i];
        }
    }
    for(int i = 30-t; i >= 0; i --){
        if(idx[i] >= m){
            idxn = idx[i];
            for(int j = 1; j <= idxn; j ++){
                b[j] = a[i][j];
            }
            f(t+1);
            return;
        }
    }
    LL sum = (1<<30)-1;
    for(int i = 1; i <= idxn; i ++){
        sum = sum & b[i];
    }
    cout << sum << '\n';
    return;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)cin >> b[i];

    idxn = n;
    f(1);


    return 0;
}