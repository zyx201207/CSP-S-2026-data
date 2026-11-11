#include<iostream>
using namespace std;
int a[200005];
char b[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<r)
	{
		int z=min(a[l],a[r]);
		if(b[l]!=b[r])
			ans+=z;
		a[l]-=z;
		a[r]-=z;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--; 
	}
	cout<<ans;
	return 0;
}
