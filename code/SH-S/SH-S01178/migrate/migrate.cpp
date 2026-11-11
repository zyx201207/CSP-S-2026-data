#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c,t,a[5005];
int s[5005];
bool g(int h,int b,int d)
{
	int e=0,l=0;
	s[h] = 0;
	for(int i=h+1;i<=b;i++)
		s[i] = 0x3f3f3f;
	for(int i=h+1;i<=b-1;i++)
	{
		for(int j=i-1;j>=h;j--)
		{
			if(abs(a[i]-a[j])<=d)
				s[i] =min(s[i],s[j]+1);
		}
	}
	for(int j=b-1;j>=h;j--)
	{
		if(abs(a[b]-a[j])<=d)
		{
			if(s[b] == s[j]+1)
			{
				l++;
			}
			else
			{
				s[b] =min(s[b],s[j]+1);
				l=1;
			}
		}
			
	}
	if(l==2)
		return true;
	return false;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t>0)
	{
		int n,d;
		cin >> n >> d;
		int ans=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[j]-a[i])>d&&g(i,j,d)==true)
					ans++;
				
			}
		}
		cout << ans << endl;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
