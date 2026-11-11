#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],len=0;
map<long long,long long>mp,yi;
bool zai[500005],flag=false;
void check()
{
	for(int i=1;i<=len;i++)
	{
		if(yi[b[i]]==0)
		{
			zai[i]=true;
			yi[b[i]]=i;
		}
		else
		{
			for(int j=yi[b[i]];j<=i-1;j++)
			{
				if(j==yi[b[j]])
				{
					yi[b[j]]=0;
				}
				zai[j]=false;
			}
			zai[i]=true;
			yi[b[i]]=i;
		}
	}
	for(int i=1;i<=len;i++)
	{
		if(zai[i]==true)
		{
			//cout<<b[i]<<" ";
			mp[b[i]]++;
		}
	}
	//cout<<"\n";
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1)
		{
			flag=true;
		}
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			len=0;
			yi.clear();
			for(int j=1;j<=n;j++)
			{
				zai[i]=false;
			}
			for(int j=i;j<=n;j++)
			{
				b[++len]=a[j];
			}
			check();
		}
		for(int i=1;i<=m;i++)
		{
			cout<<mp[i]<<" ";
		}
	}
	return 0;
}