#include <iostream>
#include <cstring>
using namespace std;
int queue[500005],n,a[500005],m,b[300005],ans[300005];
int check(int num,int t)
{
	for(int i=1;i<t;i++)
		if(queue[i]==num)
			return i;
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int c=1;c<=n;c++)
	{
		int tail=0;
		memset(queue,0,sizeof(queue));
		memset(b,0,sizeof(b));
		for(int i=c;i<=n;i++)
		{
			queue[++tail]=a[i];
			int k=check(a[i],tail);
			if(k)
				for(int j=k;j<tail;j++)
					queue[j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			b[queue[i]]=1;
		}
		for(int i=1;i<=n;i++)
			ans[i]+=b[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
