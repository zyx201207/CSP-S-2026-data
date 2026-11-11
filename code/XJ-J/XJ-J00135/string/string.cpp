#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char ch[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	int l=0,r=n+1,resl=0,resr=0;
	while(l<r)
	{
		if(resl==0)
		{
			l++;
			resl=a[l];
		}
		if(resr==0)
		{
			r--;
			resr=a[r];
		}
		if(l>=r)
		break;
		int minn=min(resl,resr);
		resl-=minn;
		resr-=minn;
		if(ch[l]!=ch[r])
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
