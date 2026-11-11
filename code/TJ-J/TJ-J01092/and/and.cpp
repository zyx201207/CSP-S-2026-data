#include<bits/stdc++.h>
using namespace std;
int n,m,x;
vector<int>a[30];
vector<int>check;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d",&n,&m);
	check.push_back(0);
	for(int i=0;i<30;i++)
	{
		a[i].push_back(0);
	}
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		int k1=k;
		for(int j=0;k>0;j++)
		{
			if(k%2)
			{
				a[j].push_back(k1);
				a[j][0]++;
				if(a[j][0]==m)
				{
					check.push_back(j);
					check[0]++;
				}
			}
			k/=2;
		}
	}
	sort(check.begin()+1,check.end(),cmp);
	int cc=check[1];
	sort(a[cc].begin()+1,a[cc].end(),cmp);
	x=a[cc][1];
	for(int i=2;i<=m;i++)
	{
		x=x & a[cc][i];
	}
	printf("%d",x);
	return 0;
}
