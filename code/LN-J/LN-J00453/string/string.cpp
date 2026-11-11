#include<bits/stdc++.h>
using namespace std;
int n;long long cnt = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    string ab = "";
    for(int i = 1; i <= n; i++){
        long long a; char b; cin >> a >> b;
        for(long long j = 1; j <= a; j++){
            ab += b;
        }
    }
    for(int i = 0; i < ab.size()/2+1; i++){
        if(ab[i] != ab[ab.size()-1-i]) cnt++;
    }
    cout << cnt;
    return 0;
}
