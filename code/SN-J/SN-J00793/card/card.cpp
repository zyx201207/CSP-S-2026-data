//SN-J00793
//张意添
//西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<long long> v[N+1];
long long a[N],ans[N];
long long n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int w=i;
		while(w<=n)
		{
			ans[a[w]]++;
			w=v[a[w]].back()+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
