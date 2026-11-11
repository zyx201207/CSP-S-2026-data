#include<bits/stdc++.h>
using namespace std;
const int N =10e5+9;
long long int cord[N];
long long int cc[N];
long long int res[N];
long long int n,m;
bool game(int s,int m)
{
	long long int l = s,r = s ;
	for(r =s + 1;r <= n;r++)
	{
		while(l < r)
		{
			if(cord[l] == cord[r])
			{
				for(long long int i = l;i < r -1;i++)
				{	
					res[cord[l]]++;	
					cord[i] = 0;
				}	
			}
			l++;
		}
		l = s;
	}
	for(long long int i = 1;i <= m;i++)
	{
		for(long long int k = s;k < n;k++)
		{
			
			if(cord[k] == i)res[i]++;
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(long long int i = 0;i < n; i++)
	{
		cin >> cc[i];
	}
	for(long long int i = 0; i < n; i++)
	{
		for(long long int j = 0; j < n; j++)
		{
			cord[j] = cc[j];
			
		}	
		game(i,m);
	}
	for(long long int i = 1;i <= m; i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}