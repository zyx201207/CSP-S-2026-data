#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s[l+j]=c;
		}
		l+=x;
	}
	long long ans=0;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}