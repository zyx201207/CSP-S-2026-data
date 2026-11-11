//SN-J00774 章梓煜 西安翱翔中学 
# include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10000000];
string c,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,l=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=0;j<a[i];j++)
		{
			s+=c[i];
		}		
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			ans++;
		}
	}
	if(l%2==0)
	{
		cout<<ans;
	}
	else
	{
		cout<<ans-2;
	}
	return 0;
}
 


