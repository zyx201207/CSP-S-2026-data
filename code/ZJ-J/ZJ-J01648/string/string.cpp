#include<bits/stdc++.h>
using namespace std;
int n,cnt,p;
long long ans;
struct node
{
	char ch;
	int num;
}vis[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %d %c",&vis[i].num,&vis[i].ch);
	}
	for(int l=1,r=n;;)
	{
		if(p==0)
		{
			if(vis[l].ch!=vis[r].ch)
			{
				ans+=min(vis[l].num,vis[r].num);
			}
			p=vis[l].num-vis[r].num;
			if(p==0){l++;r--;}
			else if(p<0){l++;}
			else{r--;}
		}
		else if(p>0)
		{
			if(vis[r].num==p)
			{
				if(vis[l].ch!=vis[r].ch)
				{
					ans+=p;
				}
				p=0;
				l++;r--;
//				cout<<"BA";
			}
			else if(p>vis[r].num)
			{
				if(vis[l].ch!=vis[r].ch)
				{
					ans+=vis[r].num;
				}
				p-=vis[r].num;
				r--;
//				cout<<"BB";
			}
			else	//p<vis[r].num
			{
				if(vis[l].ch!=vis[r].ch)
				{
					ans+=p;
				}
				p-=vis[r].num;
				l++;
//				cout<<"BC";
			}
		}
		else	//p<0
		{
			if(vis[l].num==-p)
			{
				if(vis[l].ch!=vis[r].ch)
				{
					ans-=p;
				}
				p=0;
				l++;r--;
			}
			else if(-p>vis[l].num)
			{
				if(vis[l].ch!=vis[r].ch)
				{
					ans+=vis[l].num;
				}
				p+=vis[l].num;
				l++;
			}
			else	//-p<vis[l].num
			{
				if(vis[l].ch!=vis[r].ch)
				{
					ans-=p;
				}
				p+=vis[l].num;
				r--;
			}
		}
//		printf("l=%d,r=%d,p=%d,ans=%lld\n",l,r,p,ans);
		if(l>r)
		{
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}