#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int i=1,n,s[n],a,c,t,b,o;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		s[i]=a*c;
		if(s[i]!=s[n-i+1])
		s[i]=s[n-i+1];
		b++;
	}
	cout<<b<<endl;
	return 0;
}
