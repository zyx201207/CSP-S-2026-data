#include<bits/stdc++.h>
using namespace std;
string s = "";
int a, n;
char ch;
unsigned long long cnt = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> ch;
        for(int j = 1; j <= a; j++)
            s += ch;
    }
    for(unsigned long long i = 0; i <= s.size() / 2; i++){
        if(s[i] != s[s.size() - i - 1]){
            s[s.size() - i - 1] = s[i];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
