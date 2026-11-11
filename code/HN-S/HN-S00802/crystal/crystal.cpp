#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],c=0,k,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=n;i>=1;i--)
		for(int x=1;x<=i;x++){
			c=0;
			for( j=x;j<=i;j++){
				c=c+a[i]-a[j];
			}
			if(c<=m)
			k=max(k,i-x+1);
		}	
	cout<<k;
	return 0;
} 
