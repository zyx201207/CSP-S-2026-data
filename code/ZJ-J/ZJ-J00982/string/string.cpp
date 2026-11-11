#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string S;
	long long a;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++) S+=c;
	}
	long long ans=0;
	for(long long i=0;i<S.size();i++){
		if(S[i]!=S[S.size()-i-1]) ans++;
	}
	cout<<ans/2;
	return 0;
}