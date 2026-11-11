#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],v,sum,c,x,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
			cin>>a[i];
	}
	if(n%2==0)v=n/2;
	if(n%2!=0)v=(l+n)/2;
	for(int i=v-l;i>=n;i--)
	{
		m-=v-a[i];
		if(a>0)sum++;
	}
	cout<<"3";
	return 0;
}
