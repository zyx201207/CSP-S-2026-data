#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,sum=0;
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long m;
		char c;
		cin>>m;
		cin>>c;
		for(long long j=1;j<=m;j++){
			s+=c;
		}
		sum+=m;
	}
	long long cnt=0;
	for(long long i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
