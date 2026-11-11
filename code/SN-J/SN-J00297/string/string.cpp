#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s[5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	if(n==1)
	{
		cout<<"0";
	}
	else if(n<=2)
	{
		if(s[1]==s[2])
		{
			cout<<"0";
		}
		else{
			if(a[1]>a[2])
			{
				cout<<a[2];
			}
			else
			{
				cout<<a[1];
			}
		}
	}
	else
	{
		int cnt1=1,cnt2=0;
		for(int i=2;i<=n;i++)
		{
			if(s[i-1]==s[i])
			{
				cnt1++;
			}	
		if(cnt1==n)
		{
			cout<<"0";
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt2++;
			}	
				if(cnt2==n)
				{
					cout<<n-1;
				}
			}
		}
	}
	return 0;
}
