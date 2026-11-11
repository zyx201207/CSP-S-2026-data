#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=0,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			a[0]==a[1];
		}
		if(a[i]==a[i-1]){
			x++;
		}
	}
	if(x==n){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	for(int i=1;i<=m;i++){
		int d=0;
		for(int k=n-1;k>=1;k--){
			int l=i;
			for(int j=k;j>=1;j--){
				if(l>=(a[j+1]-a[j])){
					l-=(a[j+1]-a[j]);
					a[j]=a[j+1];
					d++;
				}
				if(l<=0){
					break;
				}
			}
			if(d>maxx){
				maxx=d;
			}	
			d=0;
			l=i;
		}
	}
	cout<<maxx;
	return 0;
}