#include <bits/stdc++.h>
using namespace std;
int n;
long long num,ans;
long long a[200010];
char b[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,s2,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			s=s+b[i];
		}
		num+=a[i];
	}
	for(int i=0;i<num/2;i++)
	{
		s1=s1+s[i];
	}
	for(int i=num-1;i>=(num+1)/2;i--)
	{
		s2=s2+s[i];
	}
	cout<<s<<endl<<num<<endl<<s1<<endl<<s2<<endl;
	for(int i=0;i<(num+1)/2;i++)
	{
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
 	return 0;
} 
