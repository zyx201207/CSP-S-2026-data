#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		char ch;
		cin>>m>>ch;
		for(int j=0;j<m;j++) s+=ch;
	}
	int l=s.size(),cnt=0;
	for(int i=0;i<l/2;i++) cnt+=(s[i]!=s[l-i-1]);
	cout<<cnt<<'\n';
	return 0;
}
