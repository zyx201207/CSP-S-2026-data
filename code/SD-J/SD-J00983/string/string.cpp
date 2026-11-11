#include<bits/stdc++.h>
using namespace std;
int n;
string s=" ";
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	s.reserve(n*500);
	for(int i=1;i<=n;++i){
		int a;
		char c;
		cin>>a>>c;
		s+=string(a,c);
	}
	size_t m=s.size()-1;
	for(size_t i=1;i<=m;++i){
		if(i==m-i+1)break;
		ans+=s[i]!=s[m-i+1];
	}
	cout<<ans;
	return 0;
}
