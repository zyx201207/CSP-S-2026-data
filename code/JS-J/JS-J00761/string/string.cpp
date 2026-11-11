#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long ans = 0;
    long long a;
    long long l = 0;
    char b;
    string s;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a;
        cin >> b;
        for(int i = 0;i < a;i++){
            s[i + l] = b;
        }
        l += a;
    }
    for(long long  i = 0;i < l;i++){
        if(s[i] != s[l - 1 - i]){
            ans++;
        }
    }
    cout << ans / 2;

    return 0;
}
