#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,p,q;
long long len,ans,t[30],tt[30];
struct node
{
	int a;
	char c;
}b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		len+=b[i].a;
	}
	for(int i=1,j=n;i<=j;)
	{
		int x;
		if(x+b[i].a>len/2)
		{
			b[i].a=len/2-x-x-b[i].a+len/2;
		}
		if(b[i].c!=b[j].c)
		{
			ans+=min(b[i].a,b[j].a);
		}
		if(b[i].a<b[j].a)
		{
			b[j].a-=b[i].a;
			i++;
		}
		else if(b[i].a>b[j].a)
		{
			b[i].a-=b[j].a;
			j--;
		}
		else
		{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
