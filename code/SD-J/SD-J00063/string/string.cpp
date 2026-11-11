#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	string s;
};
node a[200005];
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].data>>a[i].s;
	}
	int l=0,r=n-1;
	while(1)
	{
		if(l>=r)break;
		if(a[l].s!=a[r].s)
		{
			sum+=min(a[l].data,a[r].data);
		}
		if(a[l].data==a[r].data)
		{
			r--;
			l++;
		}
		else if(a[l].data>a[r].data)
		{
			a[l].data-=a[r].data;
			r--;
		}
		else
		{
			a[r].data-=a[l].data;
			l++;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
