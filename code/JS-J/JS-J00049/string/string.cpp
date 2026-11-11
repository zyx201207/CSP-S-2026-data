#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        long long ls;
        cin >> ls;
        string c;
        cin >> c;
        for(int j = 1;j <= ls;j++){
            s += c;
        }
    }
    int len = s.size();
    int ans = 0;
    for(int i = 0;i <= (len - 1) / 2;i++){
        if(s[i] != s[len - 1 - i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
