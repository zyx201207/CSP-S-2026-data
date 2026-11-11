#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005],cnt=0;;
    char c[200005];
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>c[i];
	}
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2&&c[1]==c[2])
		cout<<0;
	else if(n==2)
	{
		cout<<min(a[1],a[2]);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s=s+c[i];
			}
		}
		int len=s.size();
		for(int i=1;i<=len/2-(len%2==0);i++)
		{
			for(int j=n;j>=len/2+2;j--)
			{
				if(s[i]!=s[j])
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
    return 0;
}
