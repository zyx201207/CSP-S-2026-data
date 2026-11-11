#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,ans = 0,sum = 0;
string c[200010],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j = 1;j<=a[i];j++)
		{
			s+=c[i];
		} 
	}
	for(int i = 0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-1-i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
} 
