#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a;
    char c;
    string s = "";
    for(int i = 1; i <= n; i++) {
        cin >> a >> c;
        for(int j = 1; j <= a; j++) {
            s += c;
        }
    }
    int l = 0, r = s.size() - 1;
    long long cnt = 0;
    while(l < r) {
        if(s[l] != s[r]) {
            cnt++;
            l++;
            r--;
        }
        else {
            l++;
            r--;
        }
    }
    return 0;
}
