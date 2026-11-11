#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans[35]={},a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++)
	{
		cin>>a[j];
		x=a[j];
		int i=1;
		while(x>0)
		{
			ans[i]+=(x&1);
			x=x>>1;
			i++;
		}
	}
	int k=30;
	while(ans[k]<m) k--;
	
	int sum=1073741823;
	sort(a+1,a+1+n);
	for(int j=n;j>=1;j--)
	{
		if((a[j]>>(k-1))&1==1&&m>0) {
			sum=sum&a[j];
			m--;
		}
	}
	cout<<sum;
	return 0;
}

