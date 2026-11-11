#include<bits/stdc++.h>

using namespace std;
int a[200005];
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int num;
		char s;
		cin >> num >> s;
		a[i]=num;
		ch[i]=s;
	}
	long long ans=0;
	int res=0;
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]==a[r])
		{
			if(ch[l]==ch[r])
			{
				l++,r--;
				continue;
			}
			else
			{
				ans+=a[l];
				l++,r--;
				continue;
			}
		}
		else if(a[l]>a[r])
		{
			if(ch[l]==ch[r])
			{
				a[l]-=a[r];
				r--;
				continue;
			}
			else
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
				continue;
			}
		}
		else
		{
			if(ch[l]==ch[r])
			{
				a[r]-=a[l];
				l++;
				continue;
			}
			else
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
				continue;
			}
		}
	}
	cout << ans;
	return 0;
}

