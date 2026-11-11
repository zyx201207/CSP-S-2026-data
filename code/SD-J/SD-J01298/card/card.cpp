#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[n+5],c[m+5],d[m+5];
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for (int i=1;i<=m;i++){
		c[i]=0;
		d[i]=0;
	}  	
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			for (int k=i;k<j;k++){
				if (a[k]==a[j]){
					for (int l=k;l<j;l++){
						a[l]=0;
					}
				}
			}
		}
		for (int j=i;j<=n;j++){
			d[a[j]]=1;
			a[j]=b[j];
		}
		for (int j=i;j<=n;j++){
			if (d[a[j]]){
				c[a[j]]++;
				d[a[j]]=0;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
