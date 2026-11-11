#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n, j= 0;
    cin >> n;
    string k;
    string s;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> c[i] >> k;
        j += c[i];
        for(int b = 0; b < c[i]; b++)s += k;
    }
    j-= 1;
    for(int i = 0; i< s.length(); i++){
        if(s[i] == s[j]){
            break;
        }
        j--;
        ans++;
    }
    cout << ans;
    return 0;
}
