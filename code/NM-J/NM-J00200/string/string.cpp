#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,j=0,k = 0,ans = 0;
	int a[10010];
	string s = "",s1,s2;
	char c[10010];
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < a[i];j++){
			s += c[i]; 
			k++;
		}
	}
	
	if(s.size() % 2 == 0){
		for(int i = 0;i < s.size()/2;i++){
			s1 += s[i];
		}
		for(int i = s.size()/2;i < s.size();i++){
			s2 += s[i];
		}
	}else if(s.size() % 2 != 0){
		for(int i = 0;i < (s.size()-1)/2;i++){
			s1 += s[i];
		}
		for(int i = (s.size()-1)/2+1;i < s.size();i++){
			s2 += s[i];
		}
	}
	
	for(int i = 0;i < s.size()/2;i++){
		if(s1[i] != s2[i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
