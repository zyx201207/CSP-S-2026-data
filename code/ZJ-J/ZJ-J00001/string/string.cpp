#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int a[N];
char s[N];
int sum;
string sm;
int n;
int ans=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			sm+=s[i];
		}
		
	}
	sm=' '+sm;//score 50
	for(int i=1;i<=sum/2;i++)
	{
		if(sm[i]!=sm[sum+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
