#include<bits/stdc++.h>
using namespace std;
char a[100000005];

/*struct string_num{
	long long x;
	char y;
};

string_num z[200005];*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		char s;
		cin>>t>>s;
		for(int j=1;j<=t;j++)
		{
			a[++cnt]=s;
		}
		//cin>>z[i].x>>z[i].y;
		//cnt+=z[i].x;
	}
	
	/*long long mid=cnt/2;
	long long count=0;
	int t;
	for(int i=1;i<=n;i++)
	{
		if(count<=mid && count+z[i+1].x>=mid)
		{
			t=i+1;
			break;
		}
		else
		{
			count+=z[i].x;
		}
		if(count==mid && count+z[i+1].x==mid)
		{
			t=i;
			break;
		}
		else
		{
			count+=z[i].x;
		}
	}
	
	for(int i=1;i<=t;i++)
	{
		int num=0;
		for(int j=1;j<=z[i].x;j++)
		{
			a[++num]=z[i].y;
		}
		for(int j=1;j<=z[n-i].x;i++)
		{
			a[num+j]=z[n-i].y;
		}
		int sum=z[i].x+z[n-i].x;
		for(int k=1;k<=num;i++)
		{
			if(a[i]!=a[num+1-i])
			{
				ans++;
			}
		}
	}*/
	long long ans=0;	
	

	for(int i=1;i<=(cnt/2);i++)
	{
		if(a[i]!=a[cnt+1-i])
		{
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
