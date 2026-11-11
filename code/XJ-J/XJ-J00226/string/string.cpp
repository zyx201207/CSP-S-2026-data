#include<bits/stdc++.h>
using namespace std;
long long  n,ans=0;
long long  a[10000000];
char c[1000000000],s[100000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
	s[i]=c[i]*n;
	if(s[i]==s[n+1]-i)
	{
	ans=0;
	break;	
	}
	if(s[i]!=s[i+1]||s[i-1]==s[i+1])
	{
		s[i]=s[i+1];
		ans++;
	}
	}	
	cout<<ans;
	return 0;
}
