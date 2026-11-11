#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long l=0,r=s.length()-1;
	long long ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
