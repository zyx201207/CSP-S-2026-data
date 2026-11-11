#include <bits/stdc++.h>
using namespace std;
long long n , k , len , ans;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> k >> a;
        for(int j = 1;j <= k;j++){
            s += a;
        }
    }
    len = s.size();
    if(len % 2 != 0){
        long long j = 0;
        for(long long i = len - 1;i >= len / 2 + 1;i--){
            if(s[i] != s[j]){
                ans++;
            }
            j++;
        }
        cout << ans;
    }
    else{
        long long j = 0;
        for(long long i = len - 1;i >= len / 2;i--){
            if(s[i] != s[j]){
                ans++;
            }
            j++;
        }
        cout << ans;
    }
    return 0;
}
