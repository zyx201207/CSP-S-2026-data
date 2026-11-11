#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	int n;
	cin>>n;
	int f=0;
	for(int i=0;i<n;i++){
		int m;
		string a;
		cin>>m>>a;
		for(int i=0;i<m;i++){
			s+a;
		}
	}
	for(int i=0;i*2<s.size();i++){
			if(s[i]!=s[s.size()-i]) {
			f=1;
			break;
			}
		}
		if(f=0){
		cout<<0;
		return 0;
		}
	ans=0;
	for(int i=0;i*2<s.size();i++){
		if(s[i]!=s[s.size()-i]) {
		ans++;
		}
	}
	cout<<ans;
	return 0;
}
