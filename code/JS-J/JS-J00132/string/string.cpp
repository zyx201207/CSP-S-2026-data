#include <bits/stdc++.h>
#define int long long
using namespace std;

int double_pointer_search(string s){
    int L=0,R=s.length()-1,cnt=0;
    while (L<=R){
        if (s[L]!=s[R]){
            cnt++;
        }
        L++;
        R--;
    }
    return cnt;
}

signed main(){
    freopen("string.in","r",stdin);      //Remember change me!!
    freopen("string.out","w",stdout);    //Remember change me!!

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const char endl='\n';

    int n;
    cin >> n;
    string s;
    for (int i=1;i<=n;i++){
        int x;
        char ch;
        cin >> x >> ch;
        string tmp(x,ch);
        s=s+tmp;
    }
    cout << double_pointer_search(s) << endl;

    return 0;
}
