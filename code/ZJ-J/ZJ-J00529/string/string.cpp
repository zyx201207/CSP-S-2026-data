#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0;
	cin>>n;
	vector<long long>a(n);
	vector<char>s(n);
	string t;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			t+=s[i];
		}
	}
	for(long long i=0;i<n;i++){
		if(t[i]!=t[n-i-1]){
			x++;
		}
	}
	cout<<x<<"\n";
	return 0;
}