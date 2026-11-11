#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(a[n]==i)
		{
			cout<<n<<" ";
			continue;
		}
		srand(time(0));
		cout<<rand()<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
