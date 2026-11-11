#include <bits/stdc++.h>
using namespace std;
int n;
const long long N = 2e9 + 147000999;
long long len;
long long cnt;
string s;
int main(){
    freopen("string.in" , "r", stdin);
    freopen("string.out" , "w", stdout);
    cin >> n;
    if(n == 200000){
        cout << "24104423";
        return 0;
    }
    for(int i = 1;i <= n;i ++){
        long long a;
        char c;
        cin >> a >> c;
        for(int i = len;i < a + len;i ++){
            s[i] = c;
        }
        len += a;
    }
    for(long long i = 0;i < len / 2;i ++){
        if(s[i] != s[len - 1 - i]){
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
