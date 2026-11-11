#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1;
	long long n,x,ans=0;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x>>c;
		for(int j=0;j<x;j++){
			s.push_back(c);
		}
	}
	for(long long i=s.size()-1;i>=0;i--){
		s1.push_back(s[i]);
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
