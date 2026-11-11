#include<bits/stdc++.h>
using namespace std;
long long x,y,n,a[2000010],m,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	mx=a[1];
	for(int i=1;i<=m;i++)
	{
		mx=mx&a[i];
	}
	cout<<mx;
	return 0;
}

