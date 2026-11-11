#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int cnt=0,sum=0;
	for(int i=0,j=n-1;i<j;)
	{
		if(a[i]<a[j])
		{
			if(c[i]!=c[j])
			{
				cnt+=a[i];
				a[j]-=a[i];
				i++;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
		else if(a[i]==a[j])
		{
			if(c[i]==c[j])
			{
				i++,j--;
			}
			else
			{
				cnt+=a[j];
				i++,j--;
			}
		}
		else
		{
			if(c[i]!=c[j])
			{
				cnt+=a[j];
				a[i]-=a[j];
				j--;
			}
			else
			{				
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout << cnt;
}