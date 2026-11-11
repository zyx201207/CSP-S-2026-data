//李泽畅 西安市莲湖区庆安中学 SN-J00708 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		sum+=a;
		char c;
		cin>>c;
		for(ll j=1;j<=a;j++)
		{
			s=s+c;
		}
	}
	ll ans=0,j=0;
	for(ll i=sum-1;i>=0;i--)
	{
		if(s[i]!=s[j])ans++;
		j++;
	}
	cout<<ans/2;
	return 0;
}
