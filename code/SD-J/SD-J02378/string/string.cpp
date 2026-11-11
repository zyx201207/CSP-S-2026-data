#include <bits/stdc++.h>
using namespace std;

/*
int ans[101];

void add(long long num)
{
	long long cnt=0;
	long long a=num;
	while(a)
	{
		a/=10;
		cnt++;
	}
	a=num;
	for(int i=cnt;i>=0;i--)
	{
		ans[i]+=a%10;
		a/=10;
		if(ans[i]>9)
		{
			ans[i-1]+=a[i]/10;
			a[i]%=10;
		}
	}
}
*/

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	__int128 ans=0;
	int cnt[1001];
	for(int i=0;i<=1000;i++)
		cnt[i]=0;
	string s="";
	int n;
	cin >> n;
	long long a;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> c;
		for(int j=1;j<=a;j++)
			s+=c;
		ans+=a;
	}
	
	int count=1,number=1;
	int l=1,r=ans;
	while(l<r)
	{
		if(s[l-1]!=s[r-1])
		{
			cnt[1]++;
			if(cnt[1]>9)
			{
				count=1;
				while(cnt[count]>9)
				{
					cnt[count+1]+=1;
					cnt[count]=0;
					count++;
				}
				if(count>number)
					number=count;
			}
		}
		l++,r--;
	}
	
	for(int i=number;i>=1;i--)
	{
		cout << cnt[i];
	}
	return 0;
}
