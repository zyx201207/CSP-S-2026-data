#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,u[100]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},o[5000];
	int j,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>o[i];
	for(int i=1;i<=n;i++)
	{
		for(j=i-1;j<=n;j++)
			if(j!=1&&o[j]==o[j-1]&&o[j]==o[j-i])
			u[j]=0;
			else
			u[j]++;
			for(k=0;k<=j;k++)
			{
			if(u[k]!=0&&n==i)
			cout<<o[k]<<"的出现次数为"<<u[k];
			}
	}
	return 0;
}
