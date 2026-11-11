#include<bits/stdc++.h>
using namespace std;
int t;
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		int n;char c;
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			s+=c;
		}
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}

