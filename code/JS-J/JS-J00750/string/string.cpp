#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mp[35],cnt,ans,num,su,j,o,p,answer,s[500005];
char a[500005];
struct node{
	int sum;
	char x;
}b[500005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i]>>a[i];
	ans=s[1];
	num=s[1];
	for(int i=2;i<=n+1;i++)
	{
		if(a[i]!=a[i-1])
		{
			b[++cnt].sum=ans;
			b[cnt].x=a[i-1];
			ans=s[i];
		}
		else ans+=s[i];
		num+=s[i];
	}
	for(int i=1;i<=cnt;i++)
	{
		su+=b[i].sum;
		if(su>=(num+1)/2)
		{
			j=i;
			b[i].sum--;
			break;
		}
	}
	for(int i=1,k=cnt;;)
	{
		if(i==j) o=k;
		if(k==j) p=i;
		if(o||p) break;
		if(b[i].x!=b[k].x) answer=answer+min(b[i].sum,b[k].sum);
		if(b[i].sum>b[k].sum)
		{
			b[i].sum-=b[k].sum;
			k--;
		}
		else if(b[i].sum<b[k].sum)
		{
			b[k].sum-=b[i].sum;
			i++;
		}
		else
		{
			i++;
			k--;
		}
	}
	if(o&&p) ;
	else if(o)
	{
		for(int i=o;i>j;i--)
		{
			if(b[i].x!=b[j].x) answer+=b[i].sum;
		}
	}
	else
	{
		for(int i=p;i<j;i++)
		{
			if(b[i].x!=b[j].x) answer+=b[i].sum;
		}
	}
	cout<<answer<<endl;
	return 0;
}
