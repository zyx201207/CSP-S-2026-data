#include<bits/stdc++.h>
using namespace std;
vector<int> f(40,0);
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,k=0,ans=0;
	cin>>n>>m;i=n;
	vector<int> a(n,0);
	vector<char> ok(n,'1');
	while(i--)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	i=a[0];
	while(i) i>>=1,k++;
	i=0;
	for(;i<n;i++)
	{
		int x=a[i],nowk=0;
		while(x)
		{
			int x2=x;
			if(((x>>1)<<1)!=x2) f[nowk]++;
			nowk++,x>>=1;
		}
	}
	i=k;
	for(;i>=0;i--)
	{
		if(f[i]>=m)
		{
			int now_p=1<<i;
			ans+=now_p;
			for(int j=0;j<n;j++)
			{
				if(ok[j]=='1')
				{
					int x=a[j];
					if(a[j]<now_p||(x&now_p)==0)
					{
						ok[j]='0';
						x=a[j];
						int nowk=0;
						while(x)
						{
							int x2=x;
							if(((x>>1)<<1)!=x2) f[nowk]--;
							nowk++,x>>=1;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
