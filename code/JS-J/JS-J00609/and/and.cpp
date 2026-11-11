#include<bits/stdc++.h>
using namespace std;
int n;
long long  a[10005];
int m;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long maxn = -1,maxnn = -1;
    int qwe = 11111111;
    for(int  i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
        qwe &= a[i];
    }
    for(int  i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j) maxnn = max(maxnn,(a[j]&a[i]));
        }
    }

    if(m == 1) cout << maxn;
    else if(m == n) cout << qwe;
    else if(m == 2) cout << maxnn;

    return 0;
}
