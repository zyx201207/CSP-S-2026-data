#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll nu[N];
char c[N];
ll tot=0;
ll ans=0;
string  s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nu[i]>>c[i];
		for(int i=1;i<=nu[i];i++)
		{
			s+=c[i];
		}
		tot+=nu[i];
		
	}
	ll mid=tot>>1;
	for(int i=mid;i<=tot;i++)
	{
		if(s[tot-i+1]=s[i])
		{
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
 } 
