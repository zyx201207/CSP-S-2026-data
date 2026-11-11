#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

struct node
{
	lli x,step;
}q[2000005];

lli c,t,n,d,head,tail,tx,ty,a[2000005],v[2000005],minn,ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,j,k;
	cin >> c >> t;
	while (t--)
	{
		minn=n; ans=0;
		cin >> n >> d;
		for (i=1; i<=n; i++)
			cin >> a[i];
		for (i=1; i<=n; i++)
			for (j=i+1; j<=n; j++)
			{
				head=a[i],tail=a[i]+1;
				q[1]={a[i],1};
				while (head<tail)
				{
					head++;
					for (k=1; k<=d; k++)
					{
						tx=q[head].x+k;
						if (tx<=j)
						{
							tail++;
							q[tail]={tx,q[head].step+1};
							if (tx==j&&q[tail].step<minn)
								minn=q[tail].step;
						}
					}
				}
				for (k=1; k<=tail; k++)
					if (q[k].step==minn)
						ans++;
			}
		cout << ans << endl;
	}
	/* TODO (#1#): 什么鬼啊 我还有拿分希望吗 一点都不会 */
	return 0;
}
