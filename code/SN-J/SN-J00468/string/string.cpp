#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node
{
	int k;
	char s;
}a[200050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].s;
	}
	int l=1,r=n;
	while(r-l>0)
	{
		if(a[l].k<a[r].k)
		{
			a[r].k-=a[l].k;
			if(a[l].s!=a[r].s)ans+=a[l].k;
			l++;
		}
		else if(a[l].k>a[r].k)
		{
			a[l].k-=a[r].k;
			if(a[l].s!=a[r].s)ans+=a[r].k;
			r--;
		}
		else 
		{
			if(a[l].s!=a[r].s)ans+=a[l].k;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
