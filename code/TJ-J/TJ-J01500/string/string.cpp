#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	unordered_set<char> ch;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		ch.insert(c[i]);
	}
	if(ch.size()==1)
	{
		cout<<0;
		return 0;
	}
	long long ans=0;
	long long l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]==a[r])
			{
				ans+=a[r];
				l++,r--;
			}
			else if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
				
			}
			else if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
