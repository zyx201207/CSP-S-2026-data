#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
	freopen("string2.in","r",stdin);
	freopen("string2.out","r",stdin);
	
	int n;
	cin>>n;
	
	for (int i=0; i<n; i++) {
		int a;
		string c;
		cin>>a>>c;
		for (int j=0; j<a; j++) {
			s+=c;
		}
	}
	
	int ans=0;
	for (int i=0; i<s.size()/2+1; i++) {
		if (s[i] != s[s.size()-i-1]) {
			ans++;
			s[s.size()-i-1]=s[i];
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
