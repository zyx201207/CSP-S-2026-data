/*
#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,a[200005],st[200005],en[200005],cnt=1,mid;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		st[i]=cnt;
		cnt+=a[i];
		en[i]=cnt-1;
		if(cnt>(n+1)/2)
		{
			mid=i;
		}
	}
	int rn=n;
	for(int i=1;i<mid;i++)
	{
		while(a[i]>=a[rn])
		{
			
			if(c[i]!=c[rn])
			{
				ans+=a[rn];
			}
			a[i]-=a[rn];
			st[i]+=a[rn];
			rn--;
		}
		if(c[i]!=c[rn])
		{
			ans+=a[i];
		}
		a[rn]-=a[i];
		en[rn]-=a[i];
		if(st[rn]>en[rn])
		{
			rn--;
		}
	}
	cout<<ans;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,a,cnt=1;
char c,ch[100000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=cnt;j<cnt+a;j++)
		{
			ch[j]=c;
		}
		cnt+=a;
	}
	for(int i=1;i<cnt;i++)
	{
		if(ch[i]!=ch[cnt-i+1])
		{
			ans++;
		}
	}
	cout<<(ans+1)/2;
	return 0;
}
