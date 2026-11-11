#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long ans;
long long n;
string s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(long long i=1;i<=x;i++){
			s+=c;
		}
	}
	long long len=s.size();
	string s1,s2;
	for(int i=len/2-1;i>=0;i--){
		s1+=s[i];
	}
	for(int i=len/2+1;i<len;i++){
		s2+=s[i];
	}
	if(s1==s2){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<len/2;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
