#include<bits/stdc++.h>
using namespace std;
int nm[10000086] = {};
int mn[10000086] = {};
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,flag = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> nm[i];
		for(int j = 0;j < i;j++)
		{
			if(i != j)
			{
				if(nm[i] == nm[j])
				{
					flag = 1;
					for(int k = j + 1;k < n;k++)
					{
						nm[k] = 0;
					}
				}
			}
		}
		for(int i = 0;i < n;i++)
		{
			if(nm[i] != 0)
			{
				flag++;
				mn[i] = nm[i];
			}
		}
	}
	for(int i = 0;i < n - 1;i++)
	{
		nm[i] = 0;
		for(int j = 0;j < i;j++)
		{
			if(i != j)
			{
				if(nm[i] == nm[j])
				{
					flag = 1;
					for(int k = j + 1;k < n;k++)
					{
						nm[k] = 0;
					}
				}
			}
		}
		for(int i = flag;i < flag + n;i++)
		{
			if(nm[i] != 0)
			{
				mn[i] = nm[i];
			}
		}
	}
	for(int i = 0;i < flag;i++)
	{
		
	}
	
	
	
	return 0;
} 
