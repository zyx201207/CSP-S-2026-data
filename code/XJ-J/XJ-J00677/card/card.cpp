#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[50005],t,v[30005];
struct node
{
	int dian,ju;
}q[25000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin<<n<<m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i+=)
	{
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]!=0)
			{
				for(int k=j;k>=1;k--)
				v[k]=0;
			}
			t++;
			q[t].dian=a[j];
			q[t].jun=i;v[a[j]]++;
		}
	}
	return 0;
}