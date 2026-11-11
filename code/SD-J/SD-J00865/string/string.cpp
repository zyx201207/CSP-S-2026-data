#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		long long b;
		char c;
		cin>>b>>c;
		for(long long j=1;j<=b;j++){
			a+=c;
		}
	}
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
