#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
        long long a;
        char c;
        cin >> a >> c;
        for(int i = 1 ; i <= a ; i++) s.push_back(c);
	}
	int ans = 0 , z = s.size();
	for(int i = 0 ; i < z / 2 ; i++){
        int j = s.size() - i;
        if(s[i] != s[j]) ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
