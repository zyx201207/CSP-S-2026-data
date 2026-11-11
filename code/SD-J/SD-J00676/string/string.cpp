#include<bits/stdc++.h>
#define priority_queue prq
using namespace std;
long long n;
long long ans;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char ch;
		cin>>x>>ch;
		for(int j=1;j<=x;j++) s+=ch;
	}s=' '+s;
	for(int i=1;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[(s.size()-1)-i+1]) ans++;
	}cout<<ans;
	return 0;
}

