#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    long long t = 0,sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        sum += a[i]*c[i];
        for(long long j = 1;j <= a[i];j++){
            s[t] = c[i];
            t++;
        }
    }
    bool hw = true;
    for(int i = 0;i < sum;i++){
        if(s[i] != s[sum+1-i] ) hw = false;
    }
    if(hw) cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
