#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0,l,sum=0;
char s1[100003],s2[100003];
char c;
string s;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++) 
			s+=c;
	}
	l=s.size();
	for(int i=0;i<l;i++)
		s1[i]=s[i];
	for(int j=l-1;j>=0;j--)
		s2[j]=s[j];	
	for(int i=0;i<l;i++){
		for(int j=l-1;j>=0;j--)
			if(s1[i]==s2[j]) 
				ans++;
	}
	if(ans==l-1)	cout<<"0";
	else cout<<l/2;
	return 0;
} 	
