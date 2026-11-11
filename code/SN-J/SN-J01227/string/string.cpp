#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for (int i = 0;i < n;i++){
		long long a;
		char b;
		cin >> a >> b;
		while(a){
			s += b;
			a--;
		}
	}
	string b;
	for(int i = s.size() - 1;i >= 0;i--){
		b += s[i]; 
	}
	if (s == b){
		cout << 0;
		return 0;
	}
	string c;
	int ans;
	if (s.size() % 2){
		for(int i = s.size() - 1;i > s.size() / 2;i--){
			b += s[i]; 
		}			
		for(int i = 0;i < s.size() / 2;i++){
			c += s[i];
		}
		for (int i = 0;i < s.size() / 2;i++){
			if(b[i] != c[i]){
				ans++;
			}
		}
	}
	else{
		for(int i = s.size() - 1;i > s.size() / 2 - 1;i--){
			b += s[i]; 
		}			
		for(int i = 0;i < s.size() / 2 - 1;i++){
			c += s[i];
		}
		for (int i = 0;i < s.size() / 2 - 1;i++){
			if(b[i] != c[i]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
