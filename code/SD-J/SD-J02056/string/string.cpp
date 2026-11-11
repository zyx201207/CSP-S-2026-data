#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s1=1,v=0;
	string s,sf;
	char vs;
	cin>>n;
	long long n1=n;
	while(n1--){
		long long a;
		char c;
		cin>>a>>c;
		if(vs!=c)v++;
		vs=c;
		while(a--){
			s[s1++]=c;
		}
	}
	s1--;
	for(long long i=1;i<=s1;i++){
		sf[i]=s[s1+1-i];
	}
	if(v<=1||n==1){
		cout<<0;
		return 0;
	}
	long long ans=0;
	for(long long i=1;i<=(s1+1)/2;i++){
		if(s[i]!=sf[i])ans++;
	}
	cout<<ans;
	return 0;
}
