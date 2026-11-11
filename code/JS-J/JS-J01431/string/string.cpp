#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n;
long long a[N];
char c[N];
string s;
long long ans = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        for(long long j = 1;j <= a[i];j++){
            s += c[i];
        }
    }
    for(long long i = 0;i <= s.size() / 2;i++){
        if(s[s.size() - 1 - i] != s[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
