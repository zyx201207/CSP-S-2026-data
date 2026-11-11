#include <bits/stdc++.h>
using namespace std;
int gai(string s){
	char a[10000];
	int cnt=0;
	for (int i=0;i<=s.size()/2;i++){
		if (s[i]!=s[s.size()-i]) cnt++;
	}
	return cnt;
}
bool huiwen(string s){
	char a[10000];
	int cnt=0;
	for (int i=0;i<=s.size()/2;i++){
		if (s[i]==s[s.size()-i]) cnt++;
	}
	if (cnt==s.size()/2) return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[100000];
	char b[100000];
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	string s;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	if (huiwen(s)==1) cout<<0;
	else cout<<gai(s);
	return 0;
} 
