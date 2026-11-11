#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],maxx=-100;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			maxx=max(maxx,(a[i]&a[j]));

	cout<<maxx;
	return 0 ;
}
