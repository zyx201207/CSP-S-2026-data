#include<bits/stdc++.h>
using namespace std;
char a[2000005];
int t,mi,n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int x;
		char s;
		cin>>x>>s;
		for(int i=n;i<=n+x;i++)
			a[i]=s;
		n+=x;
	}
	mi=n/2;
	for(int i=0;i<=mi;i++){
		if(a[i]!=a[n-i-1])
		ans++;
	}	
	cout<<ans;
	return 0;
}