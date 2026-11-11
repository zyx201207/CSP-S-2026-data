#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000006],f[2000006],cot,i,j,ft;
bool check(ll xx,ll y)
{
	ll i;
	bool f=1;
	for(i=xx+1;i<=y;i++)
	{
		if(!(x[i]-x[i-1]<=d&&(x[i+1]-x[i-1]>d||i==y)))
		{
			f=0;
			break;
		}
	}
	return f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		f[1]=1;
		for(i=2;i<=n;i++)
		{
			if(x[i]-x[i-1]<=d&&x[i+1]-x[i-1]>d)
			{
				f[i]=f[i-1];
			}
			else if(x[i]-x[i-1]>d)
			{
				f[i]=f[i-1]+1;
			}
			else if(x[i+1]-x[i-1]<=d)
			{
				ft=i;
				while(x[i+1]-x[ft-1]<=d&&i<=n)
				{
					i++;
				}
				f[i]=f[ft-1]+1;
			}
		}
		cot=0;
		for(i=1;i<n-1;i++)
		{
			if(f[i]!=0&&f[i+1]==0&&f[i+2]!=0)cot++;
		}
//		for(i=1;i<n;i++)
//		{
//			for(j=i+1;j<=n;j++)
//			{
//				if(check(i,j))cot++;
//			}
//		}
		cout<<cot<<"\n";
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 2
0 1 2 3 7 10 13
1 0 1 

0 1
10 3
0 3 6 7 8 9 10 13 16 19
1 1 1 0 0 2 2  2  2  2

*/