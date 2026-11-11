#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,w[107],k[107],a[107][N],t[107][N];
bool check1()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(k[i]>2) return 0;
	}
	return 1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,tt,i,j;
	long long s=0; 
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=n;i++) cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--)
	{
		cin>>x>>y;
		if(check1())
		{
			tt=x;
			while(tt!=y)
			{
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=k[i];j++)
					{
						if(a[i][j]==tt)
						{
							if(j==1&&s-a[i][2]!=0)
							{
								tt=a[i][2];
								s+=a[i][2];
							}
							else if(j==2&&s-a[i][1]!=0)
							{
								tt=a[i][1];
								s+=a[i][1];
							}
						}
					}
				}
			}
			s+=w[x]+w[y];
			cout<<s<<"\n";
		}
	}
	return 0;
}
