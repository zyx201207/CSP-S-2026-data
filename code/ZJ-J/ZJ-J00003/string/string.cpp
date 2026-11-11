#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;cin>>a>>c;
		for(int i=1;i<=a;i++)s+=c;
	}
	long long len=s.length();
	for(long long i=0;i<len/2;i++){
		long long j=len-i-1;
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
}
