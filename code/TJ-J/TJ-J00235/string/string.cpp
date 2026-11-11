#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a[10005];
	char b;
	vector<char> s;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b;
		for(int j = 1;j <= a[i];j++){
			s.push_back(b);
		}
	}
	int cnt = 0,ans = 0;
	for(int i = 0;i < s.size();i++){
		if(s[n-i+1] != s[i]){
			ans++;
		}
	}
	if(ans == ceil(n/2)){
		cout << 0;
		return 0;
	}
	for(int i = 0;i < s.size();i++){
	
	    while(s[n-i+1] != s[i]){
			s[n-i+1] = s[i];
			cnt++;
		}
	   
	}
	cout << cnt;
	return 0;
}
