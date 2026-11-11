#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct node{
    int a; char b;
}al[N], l[N], r[N];
int n;
int unsm(string s) {
    long long cnt = 0;
    long long l = 1, r = s.size();
    while(l < r) {
        cout << l << ' ' << r << endl;
        if(s[l] != s[r]) {
            cnt ++;
        }
        l ++;
        r --;
    }

    return cnt;
}


int main() {

    freopen("string.in","r", stdin);
    freopen("string.out","w",stdout);

    string s = "";

    cin >> n;
    for(int i = 1;i <= n;i ++) {
        int x; char b;
        cin >>x >> b;

        for(int i = 1;i <= x;i ++) {
            s += b;
        }
    }
    long long cnt = 0;
    long long l = 0, r = s.size() - 1;
    while(l < r) {
        //cout << s[l] << ' ' << s[r] << endl;
        if(s[l] != s[r]) {
            cnt ++;
        }
        l ++;
        r --;
    }

    cout << cnt;
    return 0;
}
