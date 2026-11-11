#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,m;
	cin>>n>>m;
	long long int Maxx=-1;
	vector<long long int> v(n+1);
	for(long long int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		for(long long int j=i+1;j+(m-2)<=n;j++)
		{
			long long int cnt=v[i];
			for(long long int z=j;z<=j+(m-2);z++)
			{
				cnt=cnt&v[z];
			}
			Maxx=max(Maxx,cnt);
		}
	}
	cout<<Maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
