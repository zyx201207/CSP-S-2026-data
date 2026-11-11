#include<bits/stdc++.h>
using namespace std;

int changeTimes(string s){
    long long cnt = 0, len = s.length();

    for(long long i = 0; i < len / 2; i++){
        if(s[i] != s[len - i - 1]){
            cnt++;
        }
    }
    return cnt;
}

int gcd(int a, int b){
    if(a % b == 0 || b % a == 0){
        return min(a, b);
    }
    int x = a, y = b;
    a = max(x, y);
    b = min(x, y);
    return gcd(a % b, b);
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    long long a[n], step;
    char c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> c[i];
        if(i == 0){
            step = a[0];
        }else{
            step = gcd(step, a[i]);
        }
        //cout << c[i] << ' ';
    }
    //cout << endl;
    //cout << step << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i] / step; j++){
            s += c[i];
        }
    }
    //cout << s << endl;
    //cout << changeTimes(s) << endl;
    cout << changeTimes(s) * step;
    return 0;
}
