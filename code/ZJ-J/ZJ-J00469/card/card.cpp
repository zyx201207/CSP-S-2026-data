#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int pos[1000000];
int cnt[1000000];
int b[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int siz=0;
		memset(pos,0,sizeof pos);
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++)
		{
			if(pos[a[j]]==0)
			{
				b[siz+1]=a[j];
				pos[a[j]]=siz+1;
				siz++;
			}else{
				int ssiz=siz;
				for(int k=pos[a[j]];k<=ssiz;k++)
				{
					b[k]=0;
					siz--;
				}
				b[siz+1]=a[j];
				pos[a[j]]=siz+1;
				siz++;
			}
			
		//for(int k=1;k<=siz;k++)
		//{
		//	cout<<b[k]<<' ';
		//}cout<<' '<<siz<<'\n';
		}
		for(int j=1;j<=siz;j++)
		{
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
