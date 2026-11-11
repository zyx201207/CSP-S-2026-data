#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[300005],ans[300005],af[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		af[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		{
			if(x[a[j]]!=0){
				for(int k=x[a[j]];k<j;k++){
					x[a[k]]=0;
					a[k]=0;
				}
			}
			x[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			a[j]=af[j];
		}
		for(int j=1;j<=m;j++){
			x[m]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
