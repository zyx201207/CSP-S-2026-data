#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    if(n == 1){
        long long i;
        char c;
        cin >> i >> c;
        cout << 0;
        return 0;
    }
    string s = "";
    while(n--){
        long long i;
        string c;
        cin >> i >> c;
        for(long long j = 1;j <= i;j++){
            s += c;
        }
    }
    long long j = s.length()-1,ans = 0;
    for(long long i = 0;i < (s.length()+1)/2;i++){
        if(s[i] != s[j]) ans++;
        j--;
    }
    cout << ans;
    return 0;
}
