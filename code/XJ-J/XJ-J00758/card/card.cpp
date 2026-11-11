#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=0;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])
			f=1;
	}
	if(f==1){
		for(int i=1;i<=m;i++)
			cout<<i;
		return 0;
	}	
	int c[m],da[n];
	for(int x=0;x<n;x++){
		int w=0;
		for(int r=x;r<n;r++){
			c[w]=a[r];
			w++;
			for(int l=0;l<r;l++)
				if(a[l]==a[r]){    {
					for(int i=l+1;i<=r;i++)
						c[i]=0;
					w=l;
				}
			}  
		}
		for(int i=0;i<=w;i++)
			da[c[i]-1]++;
	}
	for(int i=0;i<m;i++)
		cout<<da[i];
}