#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], re_fi, re_la, re_[300005], ans[300005], fi;
int Find_Fi(int st){
    for (int k = st; k <= n; k++){
        if (re_[a[k]] > 1) return k-1;}}

int Find_La(int st){
    for (int k = n; k >= st; k--){
        if (re_[a[k]] > 1) return k;}
    return n + 1;}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        re_[a[i]]++;}
    for (int i = 1; i <= n; i++){
        re_[a[i-1]]--;
        //fi = lower_bound(re_ + 1, re_ + m + 1, 2) - re_;
        //if (re_[fi] >= 2){
            re_fi = Find_Fi(i);
            re_la = Find_La(i);
            for (int j = i; j <= re_fi; j++) ans[a[j]]++;
            for (int j = re_la; j <= n; j++) ans[a[j]]++;}
        //else {
            //for (int j = i; j <= n; j++) ans[a[j]]++;}}
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;}
