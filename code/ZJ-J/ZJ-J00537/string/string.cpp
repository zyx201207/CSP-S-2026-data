#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long sum;
int n;
long long ans;
string st;
struct node
{
	int a;
	char c;
	int l,r;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].a>>a[i].c;
		sum+=a[i].a;
		for(int j=1;j<=a[i].a;++j) st+=a[i].c;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<sum/2;++i)
		if(st[i]!=st[sum-i-1]) ++ans;
	cout<<ans;
	return 0;
}
