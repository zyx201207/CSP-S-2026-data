#include <bits/stdc++.h>
using namespace std;
int main()
{
	preopen("subway.in","r",stdin);
	preopen("subway.out","w",stdout);
	int a,b,c,d,f,ab[99999999];
	cin >>a>>b>>c>>d>>f;
	for(int i=1;i<=c;i++)
	{
		cin >>ab[i];
	}
	int l,q,ac;
	int q[f][10000005];
	for(int i=1;i<=f;i++)
	{
		cin >>ac;
		for(int j=1;j<=2*ac;j++)
		{
			cin >>q[i][j];
		}
	}
	
	for(int i=1;i<=f;i++)
	{
		int mn=0;
		cin >>l>>q:
		mn+=ab[l];
		mn+=ab[q];
		for(int j=min(l,q);j<=max(l,q);j++)
		{
			for(int kl=1;kl<=2*ac;kl+=2)
			{
				if(q[i][kl]==j)
				{
					mn+=q[j][kl+1];
				}
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}