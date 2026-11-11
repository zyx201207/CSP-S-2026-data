#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n ,ans = 0;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long a;
        string c;
        cin >> a >> c;
        for(long long j = 1; j <= a; j++){
            s += c;
        }
    }
    int L = s.size();
    if(L == 1){
        cout << 0;
    }
    else if(L % 2 == 1){
        for(int i = 1; i <= L/2; i++){
            if(s[i] != s[L+1-i]){
                ans++;
                s[L + 1 - i] = s[i];
            }
        }
    }
    else{
        for(int i = 1; i <= L/2; i++){
            if(s[i] != s[L+1-i]){
                ans++;
                s[L + 1 - i] = s[i];
            }
        }
    }
    if(L % 2 == 1){
        ans--;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
