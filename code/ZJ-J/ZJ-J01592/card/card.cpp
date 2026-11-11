#include<bits/stdc++.h>
using namespace std;

int a[500500],table[300500];
int tablecnt[300500][3];//tablecnt[i][1]计当前桌面上是否有点数i的牌 [i][2]记位置 
int cnt[300500];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(table,0,sizeof(table));
		memset(tablecnt,0,sizeof(tablecnt));
		int pos=1;
		for(int j=i;j<=n;j++)
		{
			int k=a[j];
			if(tablecnt[k][1]==0)
			{
				table[pos]=k;
				pos++;
				tablecnt[k][1]=1;
				tablecnt[k][2]=pos-1;
			}
			else
			{
				pos=tablecnt[k][2]+1;
				memset(table+pos,0,sizeof(table));
				memset(tablecnt+pos,0,sizeof(table));
			}
		}
		for(int j=1;j<=pos;j++)
			cnt[table[j]]++;
	}
	
	for(int i=1;i<m;i++)
		cout<<cnt[i]<<" ";
	cout<<cnt[m];
	
	return 0;
}
