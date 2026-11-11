#include<bits/stdc++.h>
using namespace std;
int a[500];
int b[100100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		int j = 0;
		while(v)
		{
			a[j] = v%2;
			v/=2;
			j++;
		}
		for(int q = j-1; q >= 0; q--)
		{
			b[i]*=10;
			b[i]+=a[q];
			
		}
	}
	int maxx = 0;
	for(int i = 0; i < n; i++)
	{
		int q = b[i];
		for(int j = i+1; j <= n-1; j++)
		{
			int v =b[j];
			int ling = 0;
			int jing = 0;
			cout << q << v;
			while(q!=0&&v!=0)
			{
				ling*=10;
				if(q%10 == v%10)
				{
					ling++;
				}
				q/=10;
				v/=10;
				
				
			}
			int ji = 1;
			while(ling)
			{
				jing+=ling%10*ji;
				ling/10;
				ji*=2;
				
			}
			if(jing>maxx)
			{
				maxx = jing;
			}
			
			
			
		}
		
	}
	cout << maxx;
	return 0;
 } 
