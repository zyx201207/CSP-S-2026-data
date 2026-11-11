#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l[200009],ans;
struct node{
	ll st,ed,len;
	char c;
}h[200009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	if(n==1) 
	{
		printf("0");
		return 0;
	}
	h[0].ed=0;
	for(int i=1;i<=n;i++)
	{
		ll x;
		char s;
		cin>>x>>s;
		h[i].st=h[i-1].ed+1;
		h[i].ed=h[i].st+x-1;
		h[i].len=x;
		h[i].c=s;
	}
	ll r=n,j=0,i=1;
	while(1)
	{
		if(i>=r) break;
		if(h[i].c==h[r].c)
		{
			if(h[i].ed-j+1>=h[r].len) r--,j+=h[r].len-1;
			else
			{
				h[r].len-=h[i].ed-j;
				i++;
			} 
		}
		else
		{
			if(h[i].ed-j+1>=h[r].len) r--,j+=h[r].len-1,ans+=h[r].len-1;
			else
			{
				h[r].len-=h[i].ed-j+1;
				ans+=h[i].ed-j;
				i++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
