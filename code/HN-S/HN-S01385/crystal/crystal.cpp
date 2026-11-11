#include  <bits/stdc++.h>
#define MAXN int(5e5+5)
using namespace std;
long long a[MAXN];
long long MAX=LONG_LONG_MIN+5;
long long v[MAXN];
int n,m;
bool check(int x)
{
	for(int i=1;i<=n;i++) v[i]=abs(x-a[i]);
	sort(v+1,v+n+1);
	int sum=0;
	int z;
	for(z=0;sum<m&&z<n;z++)	
	{ 
		sum+=v[z+1];
	} 
	if(sum>m) {z--;}
	
//	for(int i=1;i<=n;i++)
//	{
//		cout<<v[i]<<" ";
//	}
	//cout<<z<<endl;
	//cout<<endl<<sum<<endl<<x<<endl;
	if(MAX>z) return false;
	MAX=z;
	return true;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=a[1],r=a[n],mid=0;
	while(l<r)
	{
		mid=r+((l-r)>>1);
		if(check(mid))
		{
			l=mid+1;
		} else r=mid-1;
	}
	cout<<MAX;
	return 0;
}

