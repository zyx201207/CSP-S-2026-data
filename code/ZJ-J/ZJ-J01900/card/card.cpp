#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n,m,a[50000],b[50000],c[50000],ans[50000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			b[j]=a[j];
		for(int j=1;j<=n;j++)
			c[j]=-1;
		int nn=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=-1&&c[a[j]]<=nn)
				nn=c[a[j]]-1;
			nn++;
			b[nn]=a[j];
			c[a[j]]=nn;
		}
		for(int j=1;j<=nn;j++)
			ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
