#include<bits/stdc++.h>	//骗齐AB，拿数据小的分 
using namespace std;
int n,maxn,o;	//b c
long long m,tt,a[500005];
bool A = 1,B = 1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++)
	{
//		scanf("%d ",a[i]);
		cin>>a[i];
		if(a[i] != i && A)
			A = 0;
	}

//	{
//		cin>>b;
//		
//		if(i > 1)
//			a[i - 1] = 
//		c = b;
//	}
	if(A)
	{
		while(tt < n)
		{
			if(m - maxn >= 0)
			{
				maxn ++;
				m -= maxn;
			}
			else
			 	break;
		}
		cout<<maxn + 1;
		return 0;
	}
	sort(a + 1,a + 1 + n);
	for(int i = 2;i <= n;i ++)
	{
		a[i - 1] = a[i] - a[i - 1];
		if(i == 2)
			o = a[i - 1];
		if(i > 2 && B)
			if(o != a[i - 1])
				B = 0;
	}
	if(B)
	{
		while(tt < n)
		{
			if(m - maxn >= 0)
			{
				maxn += o;
				m -= maxn;
			}
			else
			 	break;
		}
		cout<<maxn + 1;		
	}
		
	for(int i = 1;i < n;i ++)
	{
		tt = 0;
		for(int j = i;j < n;j ++)
		{
			tt += (j - i + 1) * a[j];
			if(tt <= m)
				maxn = max(maxn,j - i + 1);
			else
				break;
		}
	}
	
	cout<<maxn + 1;

	return 0;
}
