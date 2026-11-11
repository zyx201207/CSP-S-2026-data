#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	long long a;
	char c;
	long long ans=0;
	string s="";
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long len=s.size();
	for(long long i=len-1;i>=len/2;i--){
		long long v=len-i-1;
		if(s[i]!=s[v]){
			s[v]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}