#include<bits/stdc++.h>
using namespace std;
long long cnt[100100];
char t[100100];
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x;
	char y;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>y;
		cnt[i]=ans+1;
		ans+=x;
		t[i]=y;
	}
	long long i=1,j=n,a=cnt[2]-1,b=ans-cnt[n]+1;
	long long v=0,aa=a,bb=b;
	cnt[n+1]=ans;
	while(i<j)
	{
		if(t[i]!=t[j])
		{
			v+=min(aa,bb);
		}
		if(a<b)
		{
			a=cnt[i+2]-1;
			aa=a-aa;
			i++;
		}
		else if(b<a)
		{
			b=ans-cnt[j-1]+1;
			bb=b-bb;
			j--;
		}
		else 
		{
			i++;
			j--;
		}
		if(i==j)
		{
			break;
		 } 
		if(a>=ans/2+1)
		{
			cout<<v+aa-(a-(ans/2+1))*2-1;
			return 0;
		}
		if(b>=ans/2+1)
		{
			cout<<v+bb-(b-(ans/2+1))*2-1;
			return 0;
		}
	}
	cout<<v;
	return 0;
} 
