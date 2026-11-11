#include <bits/stdc++.h>
using namespace std;
long long A[600000];
long long B[600000];
long long C[600000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j;
	cin >> n >> m;
	for(i = 1;i <= n;i++)
	{
		cin >> A[i];
	}
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= n;j++)
		{
			B[j] = 0;
		}
		long long cnt = 0;
		for(j = i;j <= n;j++)
		{
			if(B[cnt] != A[j])
			{
				cnt++;
				B[cnt] = A[j];
				
			}
			else
			{
				B[cnt] = A[j];
			}
//			for(long long k = 1;k <= cnt;k++)
//			{
//				cout << B[k] << " ";
//			}
//			cout << endl;
		}
		for(j = 1;j <= m;j++)
		{
			if(B[j] != 0)
			{
				C[B[j]] ++;
			}	
		}
	}
	for(i = 1;i <= m;i++)
	{
		cout << C[i] << " ";
	}
	return 0;
} 
