#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[500005],k,j,z,b[500005],c[500005],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	z=n;
	for(i=1;i<=n;i++){
		k=0;
		for(j=1;j<=z;j++){
			if(k==1){
				a[j]=0;
				z--;
			}
			if(a[j]==d[i]){
				k=1;
			}
		}
		if(k==0){
			a[z+1]=d[i];
		}
		for(j=1;j<=z;j++){
			if(c[a[j]]!=1){
				b[a[j]]++;
				c[a[j]]=1;
			}
		}
		for(j=1;j<=m;j++){
			c[j]=0;
		}
	}
	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
