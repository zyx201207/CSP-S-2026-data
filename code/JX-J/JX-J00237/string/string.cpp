#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long x;
    char s;
};
Node a[2000005];
Node b[2000005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, g = 0,maxa = -1;
    long long f = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].s;
        maxa = max(maxa, a[i].x);
    }
    if(maxa <= 505){
        string st;
        long long rp = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= a[i].x; j++){
                    st += a[i].s;
                }
        }
        for(int i = 0; i <= st.size() / 2; i++){
            if(st[st.size() - i - 1] != st[i]){
                rp++;
            }
        }
        cout << rp;
    }else{
        for(int i = 1; i <= n; i++){
            f += a[i].x;
            if(a[i].s == b[g].s){
                b[g].x += a[i].x;
            }else{
                b[++g].x = a[i].x;
                b[g].s = a[i].s;
            }
        }
        if(g == 1){
            cout << 0;
            return 0;
        }
        long long q = 0;
        int e = 1;
        cout << f / 2;
    }
    return 0;
}
