#include<bits/stdc++.h>
using namespace std;
vector<int> a1,a2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		a1.push_back(a);
	}
	for(int l=29;l>=0;l--)
	{
		int sum=1<<l,cnt=0;
		for(auto num:a1)
			if(num&sum)
			{
				cnt++;
				a2.push_back(num);
			}
		if(cnt>=m)
		{
			ans|=sum;
			a1=a2;
		}
		a2.clear();
	}
	cout<<ans;
	return 0;
}
