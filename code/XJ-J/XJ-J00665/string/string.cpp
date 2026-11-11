#include<bits/stdc++.h>
using namespace std;
long long int n,a[200000],i,k,ans;
string b,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %c",&a[i],&b[i]);
		for(k=1;k<=a[i];k++)
		s+=b[i];
	}
	
	for(i=0,k=s.size()-1;i<k;i++,k--)
	{
		if(s[i]!=s[k])
		ans++;
	}
	cout<<ans;
	
	return 0;
}