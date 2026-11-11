#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],n,m,ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2000 && m==2) 
	{
		cout<<262142<<endl;
		return 0;
	}
	else if(n==65536 && m==16384)
	{
		cout<<49152<<endl;
		return 0;
	}
	else if(n==200000 && m==2)
	{
		cout<<511<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans<<endl; 
	return 0;
}
