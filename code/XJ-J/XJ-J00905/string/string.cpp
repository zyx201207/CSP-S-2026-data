#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	str arr[n];
	for(long long i=0;i<n;i++) cin>>arr[i].a>>arr[i].c;
	string s="";
	for(long long i=0;i<n;i++){
		for(long long j=0;j<arr[i].a;j++) s=s+arr[i].c;
	}
	
	if(n<=1){
		cout<<0;
		return 0;
	}
	long long len=s.size(),cnt=0;
	for(long long i=1;i<len;i++){
		if(i!=(len-i)){
			if(s[i]!=s[len-i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}