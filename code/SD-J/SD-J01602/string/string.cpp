#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n; 
	string s;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s=s+c;
		}
	}
	long long r=0,l=s.size()-1,cnt=0;
	while(r<=l){
		if(s[r]!=s[l]){
			cnt++;
		}
		r++;
		l--;
	}
	cout<<cnt;
	return 0;
} 

