#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	long long n,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++) s+=y;
	}for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i]) ans++;
	}cout<<ans;
	return 0;
}