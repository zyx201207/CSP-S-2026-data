#include<bits/stdc++.h>
using namespace std;
long long n,s=0,k,t=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		s=s+a[i];
	}
	char c[s];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			c[t]=b[i];
			t++;
		}
	}
	for(int i=0;i<s/2;i++){
		if(c[i]!=c[s-1-i]) k++;
	}
	cout<<k;
	return 0;
}
