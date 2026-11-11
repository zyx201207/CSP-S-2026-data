#include<bits/stdc++.h>
using namespace std;
int s[100005];
char zimu[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cha=0,left,right;
	long long diff=0; 
    cin>>n;
    if(n%2==0)
	{
		left=n/2;
		right=n/2;
	}
	else
	{
		left=n/2-1;
		right=n/2-1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>zimu[i];
	}
	int x=1;//左边进程 
	int dai=left+right;
	int m=x;//右边的进程 
	while(dai>0)
	{
		if(zimu[x]==zimu[n-m+1])
		{
			s[x]-=min(s[x],s[n-m+1]);
			s[n-m+1]-=min(s[x],s[n-m+1]);
		}
		else
		{
			diff+=min(s[x],s[n-m+1]);
			s[x]-=min(s[x],s[n-m+1]);
			s[n-m+1]-=min(s[x],s[n-m+1]);
		}
		if(s[x]==0)
		{
			x++;
			dai-=1;
		}
		else if(s[n-m+1]==0)
		{
			dai-=1;
			m++;
		}
	}
	cout<<diff;
} 
