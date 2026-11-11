#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x;
	char y;
}a[200010];
char s[180000000];
signed main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);//Trick||Treat!

	int n,cnt=1,ans=0;
	const int check=n/2;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y;
		for(int j=cnt;j<cnt+a[i].x;j++)
		{
			s[j]=a[i].y;
		}
		cnt+=a[i].x;
	}
	int len=cnt;
	cnt=0;
	/*
	if(len%2==0)
	{
		for(int i=0;i<=len/2;i++) 
		{
			if(s[i]!=s[len-i]) 
			{
				cnt++;
			//cout<<"No!!!"<<endl;
			}
		}
	}
	*/
	//else
//	{
	for(int i=1;i<=len/2;i++) 
	{
		if(s[i]!=s[len-i]) 
		{
			cnt++;
		//cout<<"No!!!"<<endl;
		}
	}
//	}
	cout<<cnt;//<<len;
	return 0;
}
