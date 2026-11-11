#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char s[500];
    int n;
    for(int i = 0;i <= n;i++){
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
