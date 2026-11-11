#include<bits/stdc++.h>
using namespace std;
long long int n,x,pp,l,r,ans;
char a,s[100000005];
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>a;
		for (int j=pp;j<=pp+x-1;j++)s[j]=a;
		pp+=x;
	}
	pp--;
	l=0;
	r=pp;
	while (l<r)
	{
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	
	}
	cout<<ans;
	return 0;
}
