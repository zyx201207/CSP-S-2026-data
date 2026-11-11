#include<bits/stdc++.h>
using namespace std;
string s1,s;
long long n,a,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>s;
		for(long long j=1;j<=a;j++)s1+=s; 
	} 
	long long len=s1.size();
	long long len2=len/2;
	for(long long i=0;i<=len2;i++){
		if(s1[i]!=s1[len-1-i])ans++;
	} 
	cout<<ans;
	return 0;
} 
