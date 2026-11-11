#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,max1[200001],a[200001],x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<=m;i++){
		max1[i]=-1;
	}
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		for(j=0;i<n;i++){
			if(max1[i]<a[j]){
				max1[i]=a[j];
				x=j;
			}
		}
		a[x]=-1;
	}
	
	cout<<a[n-1];
	return 0;
}
