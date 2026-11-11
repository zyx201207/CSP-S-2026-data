#include<bits/stdc++.h>
using namespace std;
int n,a[200001],nxt[200001],head,k,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		nxt[i-1]=i;
	}
	for(int i=29;i>=0;i--)
	{
		ans<<=1;
		int cnt=0;
		for(int j=nxt[0];j;j=nxt[j])
		{
			if((a[j]>>i)&1)
			{
				cnt++;
			}
		}
		if(cnt<k)
		{
			continue;
		}
		ans++;
		int last=0;
		for(int j=nxt[0];j;j=nxt[j])
		{
			if(((a[j]>>i)&1)==0)
			{
				nxt[last]=nxt[j];
			}
			else
			{
				last=j;
			}
		}
	}
	cout<<ans;
	return 0;
}
