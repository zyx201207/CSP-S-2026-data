#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];

//36ptrs

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0)
	
	cin>>n>>m;
	bool f=1;
	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
		if(i!=1 && a[i]<a[i-1]) f=0;
	}
	if(f) //AÐÔÖÊ 
	{
		int ans[100005];
		memset(ans, 0, sizeof(ans));
		for(int wh = 1; wh<=n; wh++)
		{
			ans[a[wh]]++;
		}
		cout<<ans[1]<<' ';
		for(int i = 2; i<=m; i++)
		{
			ans[i]=ans[i-1]+ans[i];
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2)
	{
		int an=0, bn=0;
		for(int wh = 1; wh<=n; wh++)
		{
			if(a[wh]!=a[n]) an++, bn++;
			else if(a[wh]==1) an++;
			else if(a[wh]==2) bn++;
			
		}
		cout<<an<<' '<<bn;
		return 0;
	}
	cout<<"I love YZ!\n";
	return 0;
}

//1 2 1 1 2
//1 2
//2
//1 2
//1 2
//2

