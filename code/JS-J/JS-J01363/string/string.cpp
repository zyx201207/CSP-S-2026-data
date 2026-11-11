#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);

    int n, a = 0;
    long long cnt = 0, numa;
    char ca;
    cin >> n;
    long long nums[n+1];
    char cs[n+1];
    for (int i = 1; i <= n; ++i){
        cin >> numa >> ca;
        if (ca == cs[a]) nums[a] += numa;
        else {
                ++a;
                nums[a] = numa;
                cs[a] = ca;
        }
    }

    int l = 1, r = a;
    while (l < r){
        long long numl = nums[l];
        long long numr = nums[r];
        if (cs[l] == cs[r]){
            if (numl == numr){
                ++l;
                --r;
            } else if (numl < numr){
                nums[r] -= numl;
                ++l;
            } else {
                nums[l] -= numr;
                --r;
            }
        } else {
            if (numl == numr){
                ++l;
                --r;
                cnt += numl;
            } else if (numl < numr){
                nums[r] -= numl;
                ++l;
                cnt += numl;
            } else {
                nums[l] -= numr;
                --r;
                cnt += numr;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
