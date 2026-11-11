#include<bits/stdc++.h>
using namespace std;
int n,l,r,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    while(n--){
        int a;
        char c;
        cin >> a >> c;
        while(a--){
            s += c;
        }
    }
    int len = s.length();
    r = len - 1;
    while(l <= r){
        if (s[l] != s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt << endl;
    return 0;
}
