#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int cnt = 0;
    int n;
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        string s1;
        int p;
        cin >> p >> s1;
        for(int j = 1;j <= p;j++){
            s += s1;
        }
	}
    int l = 0;
    int r = s.size() - 1;
    while(l <= r){
        if(s[l] != s[r]){
            cnt++;
        }
        l++;
        r--;
	}
    cout << cnt;
    return 0;
}
