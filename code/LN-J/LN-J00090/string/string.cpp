#include <bits/stdc++.h>
using namespace std;
string a[1000000010];
string c[1000000010];
long long cnt;
int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    string s1 = "";

    for(int i = 1; i <= n; i++){
        for(int j = 1; i <= a[i]; j++){
            s1 += c[i];
        }
    }
    string s2 = reverse(s1.begin(), s1.end());

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]){
            cnt++;
        }
    }

    cout << cnt/2;

    return 0;
}
