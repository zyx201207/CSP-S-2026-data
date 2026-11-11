#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5;
long long vis[N];
long long sum[N];
int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s;
	cin>>a>>s;
	long long d[a+10];
	for(int i=1;i<=a;i++)cin>>d[i];
	int l[N],len=0;
	for(int i=a;i>=1;i--)
	{
		if(!vis[d[i]])
		{
			len++;
			l[len]=d[i];
			vis[d[i]]=i;
		}
		else
		{
			len=a-vis[d[i]]+1;
			l[len]=d[i];
		}
		for(int j=1;j<=len;j++)
		{
			sum[l[j]]+=1;
		}
	}
	
	for(int i=1;i<=s;i++)cout<<sum[i]<<" ";
	return 0;
}
