#include <bits/stdc++.h>
using namespace std;

int n;
string s;

/*struct node
{
	int sm;
	char b;
}arr[200005];*/

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		while(a--)	s=s+b;
	}
	
	int len=s.size();
	int cnt=0,c=len/2;
   	for(int i=0;i<c;i++)
	{
		if(s[i] != s[len-i-1])	cnt++;	
	}
	/*if(n==2 && arr[1].sm == arr[2].sm)	cout<<0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i].sm != arr[n-i+1].sm)
		{
			if(arr[i].b != arr[n-i+1].b)	cnt+=arr[n-i+1].sm;
			int x=arr[i].sm-arr[n-i+1].sm;
			arr[n-i+1].sm=arr[i].sm;
			arr[n-i].sm+=x;
			cnt+=x;
			for(int j=0;;j++)
			{
				if(arr[n-i-j].sm<0)	arr[n-i-j-1].sm+=arr[n-i-j].sm;
				else break;
			}	
		}
	}*/
	cout<<cnt;
	return 0;
}
