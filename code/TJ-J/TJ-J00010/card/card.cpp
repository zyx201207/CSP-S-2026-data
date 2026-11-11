#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int Cards[n+5];
	vector <int>v;
	for(int i=1;i<=n;i++)
	{
		cin>>Cards[i];
	}
	
	for(int c=1;c<=n;c++)// n¾ÖÓÎÏ· 
	{
		for(int i=c;i<=n-(c-1);i++)
		{
			if()
			{
				v.push_back(Cards[i+(c-1)]);
			}else{
				
			}
			
		}
	}
	return 0;
 } 
