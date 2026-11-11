#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s="";
	int sum=0;
	for(int i=1;i<=n;i++){
		int siz;
		char word;
		sum+=siz;
		cin>>siz>>word;
		for(int i=1;i<=siz;i++){
			s+=word;
		}
	}
	int ans=0;
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
