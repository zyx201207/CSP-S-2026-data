#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

bool ishuiwen(vector<char>a, deque<char>b, long long tlen){
    for (long long i = 0; i < tlen; i++){
        if(a[i] == b.front()){
            b.pop_front();
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, lensum = 0, r = 0;
    cin >> n;
    vector<char>l;
    deque<char>t;
    for (int i = 1; i <= n; i++){
        long long len;
        char x;
        cin >> len >> x;
        lensum += len;
        for (int j = 1; j <= len; j++){
            l.push_back(x);
            t.push_front(x);
        }
    }
    if(ishuiwen(l, t, lensum)){
        cout << 0;
        return 0;
    }
    int j = 1;
    for (int i = lensum; i > lensum / 2 + lensum % 2 && j <= lensum / 2 + lensum % 2; i --){
        if(l[i] != l[j])
            r++;
        j++;
    }
    cout << r;
    return 0;
}
