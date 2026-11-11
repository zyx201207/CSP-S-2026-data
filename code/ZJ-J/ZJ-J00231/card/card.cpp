#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n,m,a[N],w[M] ={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int j =1;j <= n;j++)
	{
		int b[M] ={},s = 0;
		for(int i = j;i <= n;i++)
		{
			int ok =1;
			for(int k = 1;k <= s;k++)	
			{
				if(b[k]==a[i])
				{
					for(int jj = b[k];jj<=s;jj++)
					{
						b[jj] = 0;
					}
					s =k;
					b[k]=a[i];
					ok = 0;
					break;
				}
			}
			if(ok ==1)
			{
				b[s+1]=a[i];
				s++;
			}
		}
		for(int i = 1;i <= s;i++)
		{
			w[b[i]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout<<w[i]<<" ";
	}
}