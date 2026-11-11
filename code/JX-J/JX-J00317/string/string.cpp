#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, idx=1;
    string s;
    long long ans = 0;
    cin >> n;
    while(n--){
        int a;
        char c;
        scanf("%d %c", &a, &c);
        for(int i = 0; i < a; i++){
            s[idx] = c;
            idx++;
        }
    }
    int l=1, r=idx-1;
    while(l < r){
        if(s[l] != s[r]){
            s[l] = s[r];
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
