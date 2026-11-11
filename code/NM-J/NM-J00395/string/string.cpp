#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[100000000];
    int n;
    for(int i = 0;i <= n - i + 1;i++){
    	cin >> s[i];
        for (int j = 0;j <= s[i];j++){
            cin >> s[j];
            if (s[i] == s[j]){
                cout << '0';
            if (s[i] != s[j])
			    cout << '1';
			}
		}
    }
    return 0;
}

