#include<bits/stdc++.h>
using namespace std;
struct stu{
    char c;
    long long n;
}s[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int idx = 0;
    for(int i = 1; i <= n; ++i){
        idx++;
        cin >> s[idx].n >> s[idx].c;
        if(idx != 1 && s[idx-1].c == s[idx].c){
            s[idx-1].n += s[idx].n;
            idx--;
        }
    }
    int l = 1, r = idx;
    long long ans = 0;
    while(l < r){
        if(s[l].c == s[r].c){
            if(s[l].n-s[r].n < 0){
                s[r].n = -(s[l].n-s[r].n);
                l++;
            }else if(s[l].n-s[r].n > 0){
                s[l].n = s[l].n-s[r].n;
                r--;
            }else{
                l++;
                r--;
            }
        }else{
            ans += min(s[l].n, s[r].n);
            if(s[l].n-s[r].n < 0){
                s[r].n = -(s[l].n-s[r].n);
                l++;
            }else if(s[l].n-s[r].n > 0){
                s[l].n = s[l].n-s[r].n;
                r--;
            }else{
                l++;
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
