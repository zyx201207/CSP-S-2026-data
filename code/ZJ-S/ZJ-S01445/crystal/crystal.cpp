#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
int a[N];
bool fun()
{
	int d=a[2]-a[1];
	bool ok=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d) ok=false;
	}
	if(!ok) return false;
	int i=1;
	long long cnt=0;
	while(cnt<=m&&i<=n)
	{
		cnt+=a[i];
		i++;
	}
	if(cnt>m) i--;
	cout<<i;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	if(fun())
	{
		return 0;
	}
	sort(a+1,a+n+1);
	int i=1;
	long long cnt=0;
	while(cnt<=m&&i<=n)
	{
		cnt=cnt+1ll*(a[i]-a[i-1])*(i-1);
		i++;
	}
	if(cnt>m) i--;
	cout<<i-1;
	return 0;
}
