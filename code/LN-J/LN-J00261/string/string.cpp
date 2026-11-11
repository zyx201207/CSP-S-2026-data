#include <bits/stdc++.h>
using namespace std;
struct Node
{
	long long cnt;
}a[27];	
bool cmp(Node x,Node y)
{
	return x.cnt>y.cnt;
}	
void solve()
{
	int n;
	long long sum=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long m;
		char c;
		cin>>m>>c;
		if(a[c-'a'].cnt==0) cnt++;
		a[c-'a'].cnt+=m;
		sum+=m;
	}	
	sort(a,a+26,cmp);
	if(cnt==1)
		cout<<0;
	else if(sum%2==1)
		cout<<sum-a[0].cnt-1;
	else 
		cout<<sum-a[0].cnt;
}	
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
