#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s="";
	long long n;
	cin>>n;
	long long a;
	char c,pre;
	bool same=true;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
		if(i>1&&pre!=c) same=false;
		pre=c;
	}
	if(n==1||same){
		cout<<0;
		return 0;
	}
	long long len=s.size();
	long long ans=0,num=0;
	if(len%2==0){
		num=len/2;
	}
	else{
		num=(len/2)+1;
	}
	for(long long i=num;i<=len-1;i++){
		if(s[i]!=s[len-1-i]) ans++;
	}
	cout<<ans;
	return 0;
} 
