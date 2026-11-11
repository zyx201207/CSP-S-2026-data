#include <bits/stdc++.h>
using namespace std;
int a[1000000],n,m,maxb;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			maxb=max(maxb,a[i]&a[j]);}
	cout<<maxb;
	
	return 0;
} 
