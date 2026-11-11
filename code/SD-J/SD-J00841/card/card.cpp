#include<iostream> 
#include<cstring> 
using namespace std;
int a[500005];
struct aa
{
	bool bb;
	int d;	
}b[300005]; 
int q[300005],cnt[300005];
int main()
{
	//system("fc /w card.out card.out");
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,r=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		r=0;
		for(int j=1;j<=m;j++)
		{
			b[j].bb=0;
			b[j].d=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]].bb==0||r<b[a[j]].d||q[b[a[j]].d]!=a[j])
			{
				b[a[j]].bb=1;
				r++;
				b[a[j]].d=r;
				q[r]=a[j];
			}
			else
			{
				r=b[a[j]].d;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j].bb==1&&r>=b[j].d&&q[b[j].d]==j)
			{
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
