//闫思涵;
//SN-J00775;
//西安市莲湖第二学校;
#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int c[n];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[n];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[1]!=c[i])
		{
		ans++;	
		}
		else if(c[1]==c[i])
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
