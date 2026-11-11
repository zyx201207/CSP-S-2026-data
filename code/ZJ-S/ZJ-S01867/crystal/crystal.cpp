#include<bits/stdc++.h>
using namespace std;
const int N=5e5+15;
long long a[N],c[N],m;
int n,ans,L,R;
void FR()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int main()
{
	FR();
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	  cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		c[i]=c[i-1]+a[i];
		L=1,R=i;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(a[i]*(i-mid+1)-c[i]+c[mid-1]<=m)
			  R=mid-1;else
			  L=mid+1;
		}
		ans=max(ans,i-L+1);
	}
	cout<<ans;
	return 0;
}
//100 latest
