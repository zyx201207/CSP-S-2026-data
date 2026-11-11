#include<bits/stdc++.h>
using namespace std;
unsigned long long ans; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		unsigned long long num;
		char letter;
		cin>>num>>letter;
		for(unsigned long long i=1;i<=num;i++){
			s+=letter;
		}
	}
	for(int i=0;i<=s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
