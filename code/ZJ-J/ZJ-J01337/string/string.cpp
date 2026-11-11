#include<bits/stdc++.h>
using namespace std;
int n,l=1,r;
long long ans,m;
struct node
{
	long long b;
	char c;
}a[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i].b>>a[i].c;
	r=n;
	while(l<r)
	{
		m=min(a[l].b,a[r].b);
        a[l].b-=m;
		a[r].b-=m;
		if(a[l].c!=a[r].c) ans+=m;
		if(a[l].b==0) l++;
		if(a[r].b==0) r--;
	}
	cout<<ans;
	return 0;
}