#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<char>s;
vector<long long>a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    s.resize(n);
    a.resize(n);
    for (int i = 0;i < n;i++)
        cin >> a[i] >> s[i];
    int l = 0, r = n - 1;
    long long ans = 0;
    while (l <= r){
        if (s[l] == s[r]){
            if (a[l] > a[r]){
                a[l] -= a[r];
                r--;
            }
            else if(a[l] < a[r]){
                a[r] -= a[l];
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        else{
            if (a[l] > a[r]){
                ans += a[r];
                a[l] -= a[r];
                r--;
            }
            else if(a[l] < a[r]){
                ans += a[l];
                a[r] -= a[l];
                l++;
            }
            else{
                ans += a[l];
                l++;
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
