#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t;
	cin>>t;
	string s="";
	long long l=0; 
	while(t--){
		long long n;
		char c;
		cin>>n>>c;
		for(long long i=1;i<=n;i++){
			s+=c;
		}
		l+=n; 
	}
	long long sum=0;
	for(long long i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

