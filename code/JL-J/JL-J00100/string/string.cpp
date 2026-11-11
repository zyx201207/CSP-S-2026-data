#include <bits/stdc++.h>
using namespace std;
int n,t=0,ans=0;
string s=""; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		t+=a;
		for (int i=0;i<a;i++){
			s+=b;
		}
	}
	int len=s.size(),len_=s.size();
	for (int i=0;i<len/2;i++){
		if(s[i]!=s[len_-1-i]){
			ans++;
		};
	}
	cout<<ans;
	return 0;
}
