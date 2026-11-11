#include<bits/stdc++.h>
using namespace std;
int vis1[200010],vis2[200010],cnt[30];
int sz1,sz2,m;
int ans;
inline void Count(int x)
{
	int t=0;
	while(x)
	{
		if(x&(1<<t))
		{
			cnt[t]++;
			x^=(1<<t);
		}
		t++;
	}
}
inline void count(const int& sz,const int* vis)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=sz;i++)
	{
		Count(vis[i]);
	}
}
inline int find_biggest(const int left)
{
	for(int i=left;i;)
	{
		i--;
		if(cnt[i]>=m)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&sz1,&m);
	for(int i=1;i<=sz1;i++)
	{
		scanf("%d",&vis1[i]);
	}
	int last=32;
	while(true)
	{
		count(sz1,vis1);
		last=find_biggest(last);
//		cout<<last<<endl;
		if(last==-1)
		{
			break;
		}
		int t=(1<<last);
		ans|=t;
		sz2=0;
		for(int i=1;i<=sz1;i++)
		{
			if(vis1[i]&t)
			{
				vis2[++sz2]=vis1[i];
			}
		}
		sz1=sz2;
		swap(vis1,vis2);
	}
	printf("%d",ans);
	return 0;
}