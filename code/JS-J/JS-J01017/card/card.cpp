#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N  = 5e5 + 10;
inline int read() {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {x = x * 10 + c - '0';c = getchar();}
    return x;
}
int n,m,a[N];
void brute() {
    vector<int> lst(m+1,0),pos(n+1,0);
    For (i,1,n) {
        pos[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    vector<int> ans(m+1,0);
    For (i,1,n) {
        vector<int> cnt(m+1,0);
        stack<int> st;
        For (j,i,n) {
            if (cnt[a[j]]) {
                while (!st.empty()) {
                    int tp = st.top(); st.pop();
                    cnt[tp]--;
                    if (tp == a[j]) break;
                }
            }
            st.push(a[j]); cnt[a[j]]++;
        }
        For (j,1,m) {
            if (cnt[j]) ans[j]++;
        }
    }
    For (i,1,m) cout << ans[i] << " ";
}
void A() {
    vector<int> ans(m+1,0),cnt(m+1,0);
    For (i,1,n) cnt[a[i]]++;
    For (i,1,m) {
        if (cnt[i] % 2 == 1) ans[i]++;
    }
    For (i,2,n) {
        cnt[a[i-1]]--;
        if (cnt[a[i-1]] % 2 == 1) ans[i]++;
    }
    For (i,1,m) cout << ans[i] << " ";
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n = read(); m = read();
    For (i,1,n) a[i] = read();
    bool flag = true;
    For (i,2,n) {
        if (a[i-1] >= a[i]) flag = false;
    }
    if (flag) A();
    else brute();
    return 0;
}
