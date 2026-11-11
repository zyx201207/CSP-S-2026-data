#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
vector<int> number,now;
long long cnt,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		number.push_back(i);
	}
	for(int i=30;i>=0;i--)
	{
		now.clear();
		cnt=0;
		for(int j:number)
		{
			if((a[j]&(1<<i))==(1<<i))
			{
				cnt++;
				now.push_back(j);
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			number.clear();
			for(int j:now) number.push_back(j);
		}
	}
	cout<<ans;
	return 0;
}