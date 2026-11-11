#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
stack<int> s;
bool exist[300005];
int cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			s.push(a[j]);
			if(exist[a[j]]==true)
			{
				int tmp[500005];
				bool flag=false;
				int k=1;
				int scnt=0;
				while(!s.empty())
				{
					int x=s.top();
					if(x==a[j])
					{
						flag=true;
						scnt++;
						if(scnt==2)
						{
							s.pop();
							continue;
						}
						tmp[k]=x;
						k++;
						s.pop();
						continue;
					}
					if(flag==true)
					{
						s.pop();
						exist[x]=false;
					}
					else
					{
						tmp[k]=x;
						k++;
						s.pop();
					}
				}
				for(int l=1;l<k;l++)
				{
					s.push(tmp[l]);
				}
			}
			else
			{
				exist[a[j]]=true;
			}
		}
		while(!s.empty())
		{
			int x=s.top();
			cnt[x]++;
			s.pop();
			exist[x]=false;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
