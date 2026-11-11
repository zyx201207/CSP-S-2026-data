#include<bits/stdc++.h>
using namespace std;
struct str{
	int x;
	char y;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].y;
	}
	int i=1,j=n;
	while(i<j)
	{
		if(s[i].x==s[j].x)
		{
			if(s[i].y!=s[j].y)
			{
				sum+=s[i].x;
			}
			i++;
			j--;
		}
		else
		{
			long long cnt;
			cnt=min(s[i].x,s[j].x);
			if(s[i].y!=s[j].y)
			{
				sum+=cnt;
			}
			if(s[i].x<s[j].x)
			{
				i++;
				s[j].x-=cnt;
			}
			else
			{
				j--;
				s[i].x-=cnt;
			}
		}
	}
	cout<<sum;
	return 0;
}
