#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=maxx)
		{
			maxx=a[i];
		}
	}
	cout<<maxx;
	return 0;
}
