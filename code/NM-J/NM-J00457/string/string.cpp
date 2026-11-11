#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		long long a;
		string q;
		cin>>a;
		cin>>q;
		for(int j=0;j<a;j++){
			s=s+q;
		} 
	}
	int cnt;
	for(int i=0;i<s.length();i++){
		if(s[i]>=s[s.length()-i-1]){
			cout<<cnt;
			return 0;
			
		}
		if(s[i]!=s[s.length()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
