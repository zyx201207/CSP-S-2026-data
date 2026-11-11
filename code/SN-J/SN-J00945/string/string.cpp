#include<iostream>
#include<stdio.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=0;j<a;j++)s=s+c;
	}
	int ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
