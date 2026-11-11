#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n,a,cnt = 0;
    string s,s1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> s1;
        for(int j = 1;j <= a;j++){
            s += s1;
        }
    }
    long long len = s.size();
    for(int i = 0;i < (len + 1) / 2;i++){
        if(s[i] != s[len - i - 1]){
            cnt++;
            s[i] = s[len - i - 1];
        }
    }
    cout << cnt;
    return 0;
}
