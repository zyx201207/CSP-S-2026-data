#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int a, c;
    for(int i = 1;i <= n;i++){
        cin >> a >> c;
        for(int j = a;j >= 1;j--){
			s[j] = c;
        }
    }
    int l = 1, r = strlen(s);
    int cnt = 0;
    bool f = 0;
    for(int i = l;i <= r;i++){
		if(s[i] == s[i + 1]) f = 1;
		else f = 0;
	}
	if(f == 1){
		cout << 0;
		return 0;
	}	
    while(l != r){
        if(s[l] != s[r]){
            cnt++;
            l++;
            r--;
        }
    }
    cout << cnt;
    return 0;
}
