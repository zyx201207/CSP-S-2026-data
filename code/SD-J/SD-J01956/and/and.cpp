#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],sum=0,i;
int main() {
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i+1]){
			a[i+1]=a[i];
		}
		else break;
	
	}	
	cout<<a[i];
	
	return 0;
}
