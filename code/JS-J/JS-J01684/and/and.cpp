#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000005];
bool f[1000005];
//int cnt;
int answer(int n,int m,int now)
{
	if(m==0)
	{
		for(int i=1;i<=n;i++)
			f[i]=0;
		return now;
		//cout<<++cnt;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
			continue;
		f[i]=1;
		return answer(n,m-1,(now&a[i]));
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		ans=max(ans,answer(n,m-1,a[i]));
	}
	cout<<ans;
	return 0;
}

