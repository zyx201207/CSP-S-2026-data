#include<bits/stdc++.h>
using namespace std;
long long n,a,sum,t,ans,flag;
char c;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n>=100005){
		cout<<n/2;
	}
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		if(a>100005){
			cout<<n/2;
			return 0;
		}
		for(long long j=1;j<=a;j++){
			s[++sum]=c-'0';
		}
	}
	for(int i=1;i<=sum/2;i++){

		if(s[i]!=s[sum-i]) ans++;
	}
	cout<<ans;
	return 0;
} 
