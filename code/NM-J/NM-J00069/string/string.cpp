#include <bits/stdc++.h>
using namespace std;
char s[200005];
vector<char> ss, res;
int n, a[200005], l, r, k = 1;
long long pref[200005], mid, midi, ans;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> s[i];
        pref[i] = pref[i-1] + a[i];
        //mid = (pref[i] + 1) / 2;
        //if (pref[midi] < mid) midi++;
        ss.resize(pref[i], s[i]);}
    for (int i = 0; i < (pref[n] + 1) / 2; i++){
        if (ss[i] != ss[pref[n] - 1 - i]) ans++;}
    //for (long long i = 1; i <= mid; i){
    //    if (s[k] == s[n + 1 - k])}
    cout << ans;
    return 0;}
