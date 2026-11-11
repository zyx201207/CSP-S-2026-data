#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,a;
	char c;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	ll ct=0;
	for(int i=0;i<s.size();i++) ct+=(s[i]!=s[s.size()-i-1]);
	cout<<ct/2;
} 
