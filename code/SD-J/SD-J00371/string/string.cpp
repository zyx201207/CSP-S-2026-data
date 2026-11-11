#include<bits/stdc++.h>
using namespace std;
struct Node
{
	long long num;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	bool b=false;
	long long cnt=1;
	string s="";
	cin>>n;
	long long ans=0,pop=0;
	while(n--)
	{
		cin>>a[cnt].num>>a[cnt].c;
		pop+=a[cnt].num;
		
		if(cnt>=1LL*2&&(a[cnt-1].c==a[cnt].c))
		{
			a[cnt-1].num+=a[cnt].num;
			cnt--;
		}	 
		cnt++;

	}
	long long pop2=pop/2;
	if(cnt==1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		if(a[1].num>a[cnt].num)
		{
			if(a[1].num<=pop2)
			  	cout<<a[1].num;
			else cout<<pop-a[1].num; 
		}
		else if(a[cnt].num>a[1].num)
		{
			if(a[cnt].num<=pop2)
			  	cout<<a[cnt].num;
			else cout<<pop-a[cnt].num;
		}
	}
	
	return 0;
}
