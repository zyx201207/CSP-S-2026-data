#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n,m;
int l,r,mid;
int num,ans,ansl;
array<int,N> a;
array<int,N> p;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a.at(i) );
	sort(a.begin()+1,a.begin()+1+n);
	
	ansl=ans=l=1;
	for(int i=2;i<=n;i++)
	{
		ans++;
		num+=(i-l)*(a.at(i)-a.at(i-1) );
		if(num>m)
		{
			while(num>m)
			{
				num-=a.at(i)-a.at(l);
				ans--;
				l++;
			}
		}
		
		ansl=max(ansl,ans);
	}
	
	cout<<ansl<<endl;
	return 0;
}
