#include<bits/stdc++.h>
using namespace std;
int n,a[10],c[10],b;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int i=1;i<=a[i];i++)
			s+=c[i];
	}
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<l;j++)
		{
			if(s[i]==s[j]){i++;j++;b++;}
			if(i==j) break;
		}
		
	} 
	if(l/b==2) {cout<<0;return 0;}
	else
	{
		b=0;
		for(int i=0;i<l;i++)
		 for(int j=0;j<l;j++)
		 {
		 	if(s[i]!=s[j]){s[i]=s[j];return 0;}
		 } 
	}
	cout<<b;
	return 0;
}
