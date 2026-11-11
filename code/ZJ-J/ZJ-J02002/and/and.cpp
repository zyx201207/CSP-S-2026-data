#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a;
ll maxs=0;
vector<pair<long long,int> >v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int st=(int)v.size();
		for(int i=0;i<st;i++)
		{
				if(v[i].second+1==m)
				{
					maxs=max(v[i].first&a,maxs);
				}else{
					v.push_back({v[i].first&a,v[i].second+1});
				}
		}
		v.push_back({a,1});
	}
	cout<<maxs<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}