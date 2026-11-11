#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum,maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=1;
		for(int j=1;j<=m;j++){
			sum&=a[i];
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
