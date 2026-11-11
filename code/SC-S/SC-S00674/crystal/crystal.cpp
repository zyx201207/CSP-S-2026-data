#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
long long m,n;
int a[N];
int x=0,y;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(i!=m-1&&(a[i+2]-a[i])+(a[i+2]-a[i+1])<=n)
		{
			a[i]=a[i+2];
			a[i+1]=a[i+2];
			n=n-(a[i+2]-a[i])-(a[i+2]-a[i+1]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==a[i+1])
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}