#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int N=2e5+5;
int n;
long long ans;
pair<int,int> a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char s;
		cin>>a[i].f>>s;
		a[i].s=s-'a';
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].s!=a[r].s) ans+=min(a[l].f,a[r].f);
		int x=a[l].f,y=a[r].f;
		a[l].f=max(0,x-y);
		a[r].f=max(0,y-x);
		if(a[l].f==0) l++;
		if(a[r].f==0) r--;
	}
	cout<<ans;
	return 0;
}
