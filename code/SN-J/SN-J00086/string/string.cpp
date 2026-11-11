#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s,s0;
	while(n--){
		long long c;
		string s1;
		cin>>c>>s1;
		for(long long i=1;i<=c;i++){
			s+=s1;
		}
	}
	int ans=0;
	for(long long i=s.size()-1;i>=0;i--){
		s0+=s[i];
	}
	for(long long i=0;i<=s.size();i++){
		if(s[i]!=s0[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
} 
