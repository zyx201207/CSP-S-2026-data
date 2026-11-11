#include<bits/stdc++.h>
using namespace std;
long long int len=0,j,i,n,a[100000005],half,t=0;
string x,c,S;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>x;
		for(j=1;j<=a[i];j++)
		{
			S+=x;
		}
		len+=a[i];
	}
	if(len%2==0)
	{
		half=len/2-1;
		for(i=half,j=half+1;i>=0,j<=len-1;i--,j++)
		{
			if(S[i]!=S[j])
			{
				S[j]=S[i];
				t++;
			}
		}
	}
	else
	{
		half=len/2;
		for(i=half-1,j=half+1;i>=0,j<=len-1;i--,j++)
		{
			if(S[i]!=S[j])
			{
				S[j]=S[i];
				t++;
			}
		}
	}
	cout<<t;
	return 0;
}





