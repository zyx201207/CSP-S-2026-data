#include<bits/stdc++.h>
using namespace std;
long long n, cnt;
vector<char> s;
long long f(long long x){
    long long ans = 0;
    for(int i = 0; i < x / 2; i ++){
        if(s[i] != s[x - i - 1]){
            ans ++;
        }
    }
    return ans;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i ++){
        int x;
        char y;
        cin >> x >> y;
        for(int j = 1; j <= x; j ++){
            s.push_back(y);
            cnt ++;
        }
    }
    long long x = f(cnt);
    x = min(x, cnt - x);
    cout << x;
    return 0;
}
/*
3
2 a
2 b
1 c
*/
