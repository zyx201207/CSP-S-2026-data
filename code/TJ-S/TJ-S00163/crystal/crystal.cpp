#include<bits/stdc++.h>
#include<vector>
using namespace std ;

int n ,m ;
int cnt = 0;
int ans = 0;
int a[10005];

vector<int> v;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 0 ; i <n ; i++)
	{
		cin >> a[i];
	}
	
	while (cnt!=m) 
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(a[i]!=a[i+1])
			{
				a[i]+=1;
				cnt++;
			}
			
			if(a[i]==a[i+1])
			{
				ans ++;
			}
		}
		
		if(cnt == m )
			break; 
	}
	
	cout << ans ;
	
	return 0;
}
