#include<bits/stdc++.h>//T2 WA 1
#define int long long
#define endl '\n'
using namespace std;
const int N=4e5;
struct node{
	int num;
	char c;
}a[N];
int ans,k;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
	}
	int mid=n/2;
//	if(n%2==0)k=1;
//	else k=2;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].c!=a[n-i+1].c) ans+=a[i].num;
	}
	cout<<ans;
	/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
	*/
	return 0;
}
