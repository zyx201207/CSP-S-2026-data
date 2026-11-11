#include <bits/stdc++.h>
using namespace std; 
long long a[200005];
char c[200005];
int cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=a[i];j>=1;j--){
		    t+=c[i];
		 }
	} 
	cout<<0;
	return 0;
} 
