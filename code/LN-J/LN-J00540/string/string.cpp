#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,l=0,ans=0;
	char c;
	string s="";
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=0;i<a;i++)s=s+c;
		l+=a;
	}
	string s1="",s2="";
	long long i=0,j=l-1;
	while(i<=j){
		s1=s1+s[i],s2=s2+s[j];
		i++,j--;
	}
	l=s1.size();
	for(long long i=0;i<l;i++)if(s1[i]!=s2[i])ans++;
	cout<<ans<<'\n';
	return 0;
}
