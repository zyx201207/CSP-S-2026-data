#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
vector<int> pos[N];
void play(int x)
{
	list<int> desk;
	for(int i=x;i<=n;i++)
	{
//		cout<<a[i]<<"\n";
		if(i==x)
		{
			desk.push_back(a[i]);
			continue;
		}
		desk.erase(find(desk.begin(),desk.end(),a[i]),desk.end());
		desk.push_back(a[i]);
//		for(auto i:desk)cout<<i<<" ";
//		cout<<"\n";
	}
	for(auto i:desk)
	{
		ans[i]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(!f)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(j!=i && a[j-1]==a[j]) continue;
				ans[a[j]]++;
			}
		}
		cout<<ans[1];
		for(int i=2;i<=m;i++) cout<<" "<<ans[i];
		return 0;
	}
	for(int i=1;i<=n;i++) play(i);
	cout<<ans[1];
	for(int i=2;i<=m;i++) cout<<" "<<ans[i];
	return 0;
}