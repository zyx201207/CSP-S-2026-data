#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;	
	cin>>n;
	int a[n];
	int b=0,d=0;
	char c[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		b+=a[i];
	}	
	char s[b];
	for(int i=0;i<n;i++)
	{
		int j=0;
		for(;j<a[i];j++)
			s[j+d]=c[i];
		d=j;
	}
	d=0;
	for(int i=0,j=b-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
			d++;
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
