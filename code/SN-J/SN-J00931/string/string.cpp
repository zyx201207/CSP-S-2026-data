#include<bits/stdc++.h>
using namespace std;
const long long Most=10000017;
long long a[Most];
char c[Most];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	char p=c[0];
	char k;
	long long o;
	for(long long i=0;i<n;i++){
		k=c[i];
		if(k==p){
			o++;	
		}
	}
	if(o==n){
		cout<<0;
		return 0;
	}
	string s="";
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
