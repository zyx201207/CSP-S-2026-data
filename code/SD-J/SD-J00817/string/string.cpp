#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
string c[200005],s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	for(long long i=s.size()-1;i>=0;i--){
		s1=s1+s[i];
	}
	if(s==s1){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
