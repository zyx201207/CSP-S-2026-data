#include<iostream> 
#include<algorithm>
#include<cmath>
using namespace std;
struct aa
{
	int z,d,k;
}a[200005];
bool b[200005][35];
bool cmp(aa a,aa b)
{
	if(a.k>b.k)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	//system("fc /w and.out and.out");
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].z;
		int c=a[i].z;
		a[i].d=i;
		for(int j=30;j>=1;j--)
		{
			b[i][j]=c%2;
			c=c/2;
		}
	}
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j].k=b[a[j].d][i];
		}
		sort(a+1,a+n+1,cmp);
		if(a[m].k==1)
		{
			sum=sum+pow(2,30-i);
			for(int j=m+1;j<=n;j++)
			{
				if(a[j].k==0)
				{
					n=j-1;
					break;
				}
			}
		}
	}
	cout<<sum<<"\n";
	return 0;
}
