#include<bits/stdc++.h>
using namespace std;
long long jie(int a)
{
	if (a<=1)
	{
		return 1;
	}
	else
	{
		return a*jie(a-1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int zmjjkk,num;
	cin>>zmjjkk>>num;
	int n[num]={0},min[num]={0,0};
	long long d[num]={0},x[num][100000]={0};
	for(int i=0;i<num;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++)
		{
			cin>>x[i][j];
		}
	}
	for(int c=0;c<num;c++)
	{
		long long cnt=0;
		int zoe=n[c];
		int ans=0;
		long long y[jie(zoe)]={0},jas[jie(zoe)]={0};
		for(int i=0;i<n[c]-1;i++)
		{
			for(int j=i+1;j<n[c];i++)
			{
				y[cnt]=x[c][j]-x[c][i];
				cnt++;
			}
		}
		for(int i=0;i<cnt-2;i++)
		{
			for(int j=i+1;j<cnt-1;i++)
			{
				if(y[i]==y[j])
				{
					jas[y[i]]+=1;
				}
			}
		}
		for(int i=0;i<jie(zoe);i++)
		{
			if(jas[i]==2)
			{
				ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
